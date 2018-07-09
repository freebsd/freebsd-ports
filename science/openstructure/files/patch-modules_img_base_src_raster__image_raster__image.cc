--- modules/img/base/src/raster_image/raster_image.cc.orig	2018-07-09 00:06:35 UTC
+++ modules/img/base/src/raster_image/raster_image.cc
@@ -25,7 +25,7 @@
 */
 
 #ifndef __APPLE__
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 #include <cmath>
 #include <iostream>
