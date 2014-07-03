--- src/modules/imagery/imagery_opencv/opencv.h.orig	2014-01-14 11:27:53.000000000 +0100
+++ src/modules/imagery/imagery_opencv/opencv.h	2014-01-14 11:28:44.000000000 +0100
@@ -73,7 +73,8 @@
 #include "MLB_Interface.h"
 
 //---------------------------------------------------------
-#include <opencv/cv.h>
+#include <opencv2/core/core_c.h>
+#include <opencv2/imgproc/imgproc_c.h>
 
 
 ///////////////////////////////////////////////////////////
