--- ./src/videoglwidget.cpp.orig	2012-04-16 13:32:51.680661508 +0200
+++ ./src/videoglwidget.cpp	2012-04-16 13:33:32.610551829 +0200
@@ -1,6 +1,7 @@
 
 #include <QtGui>
 #include <QtOpenGL>
+#include <GL/glu.h>
 #include "videoglwidget.h"
 
 #ifndef GL_TEXTURE_RECTANGLE_EXT
