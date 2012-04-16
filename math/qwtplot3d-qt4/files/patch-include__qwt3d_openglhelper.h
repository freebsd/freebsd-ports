--- ./include/qwt3d_openglhelper.h.orig	2012-04-16 21:57:23.639051666 +0000
+++ ./include/qwt3d_openglhelper.h	2012-04-16 21:57:23.713053060 +0000
@@ -6,6 +6,7 @@
 #include <qgl.h>
 #else
 #include <QtOpenGL/qgl.h>
+#include <GL/glu.h>
 #endif
 
 namespace Qwt3D
