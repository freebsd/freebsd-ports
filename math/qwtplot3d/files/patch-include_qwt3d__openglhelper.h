--- include/qwt3d_openglhelper.h.orig	2018-11-26 20:04:53 UTC
+++ include/qwt3d_openglhelper.h
@@ -6,6 +6,7 @@
 #include <qgl.h>
 #else
 #include <QtOpenGL/qgl.h>
+#include <GL/glu.h>
 #endif
 
 namespace Qwt3D
