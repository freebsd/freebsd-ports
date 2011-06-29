--- libavfilter/vf_libopencv.c.orig	2011-06-27 21:27:01.521012341 +0200
+++ libavfilter/vf_libopencv.c	2011-06-27 21:27:16.839540294 +0200
@@ -25,8 +25,7 @@
 
 /* #define DEBUG */
 
-#include <opencv/cv.h>
-#include <opencv/cxcore.h>
+#include <opencv2/imgproc/imgproc_c.h>
 #include "libavutil/avstring.h"
 #include "libavutil/file.h"
 #include "avfilter.h"
