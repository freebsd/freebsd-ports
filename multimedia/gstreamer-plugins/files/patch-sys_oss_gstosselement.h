--- sys/oss/gstosselement.h.orig	Tue Mar  9 16:46:05 2004
+++ sys/oss/gstosselement.h	Tue Mar  9 16:46:14 2004
@@ -23,6 +23,7 @@
 #ifndef __GST_OSS_ELEMENT_H__
 #define __GST_OSS_ELEMENT_H__
 
+#include <sys/types.h>
 #include <gst/gst.h>
 
 /* debugging category */
