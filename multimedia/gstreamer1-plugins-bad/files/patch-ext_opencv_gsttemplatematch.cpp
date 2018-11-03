--- ext/opencv/gsttemplatematch.cpp.orig	2018-03-23 20:45:15 UTC
+++ ext/opencv/gsttemplatematch.cpp
@@ -64,6 +64,8 @@
 #include "../../gst-libs/gst/gst-i18n-plugin.h"
 #include "gsttemplatematch.h"
 #include <opencv2/imgproc/imgproc_c.h>
+#include <opencv2/imgproc/types_c.h>
+#include <opencv2/imgcodecs/imgcodecs_c.h>
 
 GST_DEBUG_CATEGORY_STATIC (gst_template_match_debug);
 #define GST_CAT_DEFAULT gst_template_match_debug
