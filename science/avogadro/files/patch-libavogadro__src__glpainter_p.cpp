--- ./libavogadro/src/glpainter_p.cpp.orig	2011-04-25 05:22:18.000000000 +0000
+++ ./libavogadro/src/glpainter_p.cpp	2012-05-01 21:59:50.998695297 +0000
@@ -43,6 +43,8 @@
 #include <QVarLengthArray>
 #include <Eigen/Geometry>
 
+#include <GL/glu.h>
+
 namespace Avogadro
 {
 
