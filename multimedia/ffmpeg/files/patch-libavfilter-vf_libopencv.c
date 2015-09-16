--- libavfilter/vf_libopencv.c.orig	2015-06-19 20:44:50 UTC
+++ libavfilter/vf_libopencv.c
@@ -23,8 +23,7 @@
  * libopencv wrapper functions
  */
 
-#include <opencv/cv.h>
-#include <opencv/cxcore.h>
+#include <opencv2/imgproc/imgproc_c.h>
 #include "libavutil/avstring.h"
 #include "libavutil/common.h"
 #include "libavutil/file.h"
