--- ./qtiplot/src/plot3D/Cone3D.cpp.orig	2010-09-27 07:12:48.000000000 +0000
+++ ./qtiplot/src/plot3D/Cone3D.cpp	2012-04-16 21:30:38.879058155 +0000
@@ -31,6 +31,7 @@
 #include "qwt3d_plot.h"
 #include <qwt3d_curve.h>
 #include "Cone3D.h"
+#include "GL/glu.h"
 
 using namespace Qwt3D;
 
