//Algoritma Bresenham

#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

using namespace std;

//identifier fungsi
void init();
void display(void);
void bresenham(void);

//  posisi window di layar
int window_x;
int window_y;

//  ukuran window
int window_width = 480;
int window_height = 480;

//  judul window
char *judul_window = "Algoritma Bresenham";

void main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	// set posisi window supaya berada di tengah 
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height); //set ukuran window 
	glutInitWindowPosition(window_x, window_y); //set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // set display RGB dan double buffer
	glutCreateWindow(judul_window); //set judul window

	
	init(); //jalankan fungsi init 
	glutDisplayFunc(display); //  set fungsi display
	glutMainLoop(); // set loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //set warna backg1round 
	glColor3f(1.0, 0.0, 1.0); //set warna titik
	glPointSize(2.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan 
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(-800.0, 800.0, -800.0, 800.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	bresenham(); //jalankan fungsi bresenham
	glutSwapBuffers(); //swap buffer 
}

void bresenham(void) {
	int x1, y1, x2, y2, x, y, dx, dy, xend, p, duady, duadydx,sx,sy,yend;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2i(0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(0, 0);
	glVertex2i(0, 800);
	glVertex2i(0, 0);
	glVertex2i(800, 0);
	glVertex2i(0, 0);
	glVertex2i(-800, 0);
	glVertex2i(0, 0);
	glVertex2i(0, -800);
	glEnd();
	//tentukan titik awal dan akhir
	x1 = -400;
	y1 = -200;
	x2 = -400;
	y2 = 400;
	//x = x1;
	//y = y1;
	
	//hitung dx dan dy
	dx = fabs(x2 - x1);
	dy = fabs(y2 - y1);
	
	//hitung p 
	p = 2 * dy - dx;
	duady = 2 * dy;
	duadydx = 2 * (dy - dx);
	cout << "x = " << duadydx << endl;
	//tentukan titik awal dan akhir
	if (x1 > x2) {
		x = x2;
		y = y2;
		xend = x1;
		yend = y1;
	}
	else if (x1 == x2) {
		x = x1;
		if (y1 > y2) {
			y = y2;
			xend = y1;
			yend = y1;
		}
		else {
			y = y1;
			xend = y2;
			yend = y2;
		}
		
	}
	else if (y1 == y2) {
		y = y1;
		yend = y2;
		if (x1 > x2) {
			x = x2;
			xend = x1;
		}
		else {
			x = x1;
			xend = x2;
		}
		
	}
	else
	{
		x = x1;
		y = y1;
		xend = x2;
		yend = y2;
		//cout << "x = " << x << endl;
		//cout << "xend = " << xend << endl;

	}

	//gambar titik awal
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	//cout << "x = " << x << endl;
	//cout << "xend = " << xend << endl;
	//cout <<" p = "<< p << endl;
	//perulangan untuk menggambar titik-titik 
	int k;
	if (x1 == x2) {
		k = y;
	}
	else if (y1 == y2) {
		k = x;
	}
	else { k = x; }
	cout << " xend = " << xend << endl;
	while (k < xend) {
		if (x1 != x2) {
			x++;
		}
		if (p < 0) {
			p += duady;
		}
		else if(p>=0)
		{
			//cout << " test3" << endl;
			//cout << " y= " << y << endl;
			//cout << " y2= " << y2 << endl;

			if (y > yend) {
				y--;
				//cout << " test" << endl;
			}
			else if(y<yend){
				y++;
				//cout << " test1" << endl;
			}
			p += duadydx;
			
		}
		//cout << " y = " << y << endl;
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(x, y);
		k++;
	}

	glEnd();
	glFlush();
}

