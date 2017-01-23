--- src/tools/imagery/imagery_opencv/opencv.h.orig	2016-06-29 05:55:46 UTC
+++ src/tools/imagery/imagery_opencv/opencv.h
@@ -74,7 +74,8 @@
 
 //---------------------------------------------------------
 #include <opencv/cv.h>
-
+#include <opencv2/core/core_c.h>
+#include <opencv2/imgproc/imgproc_c.h>
 
 ///////////////////////////////////////////////////////////
 //														 //
