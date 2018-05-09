--- ./ext/opencv/gsttemplatematch.c.orig	2018-05-02 20:00:45.872112000 +0000
+++ ./ext/opencv/gsttemplatematch.c	2018-05-02 20:01:19.130929000 +0000
@@ -66,6 +66,8 @@
 #include "gstopencvutils.h"
 #include "gsttemplatematch.h"
 
+#include "opencv2/imgcodecs/imgcodecs_c.h"
+
 GST_DEBUG_CATEGORY_STATIC (gst_template_match_debug);
 #define GST_CAT_DEFAULT gst_template_match_debug
 
