--- libavfilter/vf_libopencv.c.orig	2012-08-05 14:09:37.882506740 +0200
+++ libavfilter/vf_libopencv.c	2012-08-05 14:10:24.508510133 +0200
@@ -25,8 +25,7 @@
 
 /* #define DEBUG */
 
-#include <opencv/cv.h>
-#include <opencv/cxcore.h>
+#include <opencv2/imgproc/imgproc_c.h>
 #include "libavutil/avstring.h"
 #include "libavutil/file.h"
 #include "avfilter.h"
