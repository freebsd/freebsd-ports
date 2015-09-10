--- src/modules/imagery/imagery_opencv/opencv.h.orig	2015-02-26 07:51:59 UTC
+++ src/modules/imagery/imagery_opencv/opencv.h
@@ -74,7 +74,8 @@
 
 //---------------------------------------------------------
 #include <opencv/cv.h>
-
+#include <opencv2/core/core_c.h>
+#include <opencv2/imgproc/imgproc_c.h>
 
 ///////////////////////////////////////////////////////////
 //														 //
