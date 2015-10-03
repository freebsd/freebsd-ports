--- ext/opencv/gstmotioncells.h.orig	2015-06-19 09:23:16.588484000 +0200
+++ ext/opencv/gstmotioncells.h	2015-06-19 09:23:42.718303000 +0200
@@ -45,6 +45,8 @@
 #ifndef __GST_MOTIONCELLS_H__
 #define __GST_MOTIONCELLS_H__
 
+#include <sys/time.h>
+
 #include <gst/gst.h>
 #include <opencv2/core/core_c.h>
 
