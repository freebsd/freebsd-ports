--- src/modules_images/modules_opencv/opencv/opencv.h.orig	2013-12-03 19:17:30.000000000 -0500
+++ src/modules_images/modules_opencv/opencv/opencv.h	2013-12-03 19:19:37.000000000 -0500
@@ -73,7 +73,8 @@
 #include "MLB_Interface.h"
 
 //---------------------------------------------------------
-#include <opencv/cv.h>
+#include <opencv2/core/core_c.h>
+#include <opencv2/imgproc/imgproc_c.h>
 
 
 ///////////////////////////////////////////////////////////
