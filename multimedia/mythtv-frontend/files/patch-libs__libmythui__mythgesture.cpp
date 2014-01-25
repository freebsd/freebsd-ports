--- libs/libmythui/mythgesture.cpp.orig	2013-09-18 16:06:08.000000000 -0400
+++ libs/libmythui/mythgesture.cpp	2014-01-22 08:20:33.000000000 -0500
@@ -28,6 +28,7 @@
 
 #include "mythgesture.h"
 
+#include <cstdlib>
 #include <cmath>
 #include <algorithm>
 
@@ -283,7 +284,7 @@
     int dely = p.y() - points.back().y();
 
     /* step by the greatest delta direction */
-    if (abs(delx) > abs(dely))
+    if (std::abs(delx) > std::abs(dely))
     {
         float iy = points.back().y();
 
