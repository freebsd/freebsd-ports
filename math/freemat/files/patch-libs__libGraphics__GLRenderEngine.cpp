--- ./libs/libGraphics/GLRenderEngine.cpp~	2012-05-20 11:26:18.000000000 -0300
+++ ./libs/libGraphics/GLRenderEngine.cpp	2012-05-20 11:26:30.000000000 -0300
@@ -23,6 +23,8 @@
 #include <math.h>
 #include "IEEEFP.hpp"
 
+#include <GL/glu.h>
+
 GLRenderEngine::GLRenderEngine(QGLWidget *widget, double x1, double y1,
 			       double width, double height) {
   m_x1 = x1;
