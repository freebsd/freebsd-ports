--- ext/opencv/gsttemplatematch.cpp.orig	2018-05-02 20:48:22.600036000 +0000
+++ ext/opencv/gsttemplatematch.cpp	2018-05-02 20:50:39.989630000 +0000
@@ -64,6 +64,8 @@
 #include "../../gst-libs/gst/gst-i18n-plugin.h"
 #include "gsttemplatematch.h"
 #include <opencv2/imgproc/imgproc_c.h>
+#include <opencv2/imgproc/types_c.h>
+#include <opencv2/imgcodecs/imgcodecs_c.h>
 
 GST_DEBUG_CATEGORY_STATIC (gst_template_match_debug);
 #define GST_CAT_DEFAULT gst_template_match_debug
