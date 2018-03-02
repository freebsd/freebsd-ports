--- libs/libmythui/mythgesture.cpp.orig	2015-06-16 16:03:30 UTC
+++ libs/libmythui/mythgesture.cpp
@@ -28,6 +28,7 @@
 
 #include "mythgesture.h"
 
+#include <cstdlib>
 #include <cmath>
 #include <algorithm>
 #include <complex>
@@ -284,7 +285,7 @@ bool MythGesture::record(const QPoint & p)
     int dely = p.y() - points.back().y();
 
     /* step by the greatest delta direction */
-    if (abs(delx) > abs(dely))
+    if (std::abs(delx) > std::abs(dely))
     {
         float iy = points.back().y();
 
