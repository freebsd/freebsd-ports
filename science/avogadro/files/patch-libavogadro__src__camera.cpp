--- ./libavogadro/src/camera.cpp.orig	2011-04-25 05:22:18.000000000 +0000
+++ ./libavogadro/src/camera.cpp	2012-05-01 21:59:52.241696067 +0000
@@ -26,6 +26,8 @@
 #include "glwidget.h"
 #include <avogadro/molecule.h>
 
+#include <GL/glu.h>
+
 using namespace Eigen;
 
 namespace Avogadro
