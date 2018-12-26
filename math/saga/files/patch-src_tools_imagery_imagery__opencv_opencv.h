--- src/tools/imagery/imagery_opencv/opencv.h.orig	2018-11-22 07:53:06 UTC
+++ src/tools/imagery/imagery_opencv/opencv.h
@@ -73,7 +73,8 @@
 
 //---------------------------------------------------------
 #include <opencv/cv.h>
-
+#include <opencv2/core/core_c.h>
+#include <opencv2/imgproc/imgproc_c.h>
 
 ///////////////////////////////////////////////////////////
 //														 //
