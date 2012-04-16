--- ./3rdparty/qwtplot3d/include/qwt3d_openglhelper.h.orig	2011-08-24 10:25:09.000000000 +0000
+++ ./3rdparty/qwtplot3d/include/qwt3d_openglhelper.h	2012-04-16 20:17:06.461052631 +0000
@@ -6,6 +6,7 @@
 #include <qgl.h>
 #else
 #include <QtOpenGL/qgl.h>
+#include <GL/glu.h>
 #endif
 
 namespace Qwt3D
