--- src/modules/imagery/imagery_opencv/opencv.h.orig	2015-12-21 09:38:29 UTC
+++ src/modules/imagery/imagery_opencv/opencv.h
@@ -74,7 +74,8 @@
 
 //---------------------------------------------------------
 #include <opencv/cv.h>
-
+#include <opencv2/core/core_c.h>
+#include <opencv2/imgproc/imgproc_c.h>
 
 ///////////////////////////////////////////////////////////
 //														 //
