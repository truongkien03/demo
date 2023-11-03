#include <GL/glut.h>
#include <cmath>

int windowWidth = 800;
int windowHeight = 600;

void drawCircle(int x, int y, int radius) {
    glBegin(GL_POINTS);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159265358979323846 / 180;
        int newX = x + static_cast<int>(radius * cos(theta));
        int newY = y + static_cast<int>(radius * sin(theta));
        glVertex2i(newX, newY);
    }
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Màu trắng

    // Vẽ đường tròn bán kính 30 tại (20, 20)
    drawCircle(20, 20, 30);

    // Vẽ đường tròn bán kính 20 tại (0, 0)
    drawCircle(0, 0, 20);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Circle Drawing");
    gluOrtho2D(0, windowWidth, 0, windowHeight);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
