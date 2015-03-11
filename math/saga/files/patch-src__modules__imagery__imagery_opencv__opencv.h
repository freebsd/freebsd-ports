--- src/modules/imagery/imagery_opencv/opencv.h.orig	2014-09-02 12:47:18.000000000 +0200
+++ src/modules/imagery/imagery_opencv/opencv.h	2014-09-02 12:48:48.000000000 +0200
@@ -74,7 +74,8 @@
 
 //---------------------------------------------------------
 #include <opencv/cv.h>
-
+#include <opencv2/core/core_c.h>
+#include <opencv2/imgproc/imgproc_c.h>
 
 ///////////////////////////////////////////////////////////
 //														 //
