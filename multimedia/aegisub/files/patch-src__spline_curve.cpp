--- src/spline_curve.cpp.orig	2014-08-06 00:07:08.000000000 +0900
+++ src/spline_curve.cpp	2014-08-06 00:07:27.000000000 +0900
@@ -35,6 +35,7 @@
 #include "spline_curve.h"
 #include "utils.h"
 
+#include <algorithm>
 #include <limits>
 
 SplineCurve::SplineCurve(Vector2D p1) : p1(p1), type(POINT) { }
