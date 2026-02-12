Adaptation for GStreamer 1.28.0

--- gst/vaapi/gstvaapivideobufferpool.h.orig	2025-12-25 14:44:26 UTC
+++ gst/vaapi/gstvaapivideobufferpool.h
@@ -23,7 +23,7 @@
 #ifndef GST_VAAPI_VIDEO_BUFFER_POOL_H
 #define GST_VAAPI_VIDEO_BUFFER_POOL_H
 
-#include <gst/video/gstvideopool.h>
+#include <gst/video/video.h>
 #include <gst/vaapi/gstvaapidisplay.h>
 #include <gst/vaapi/gstvaapisurfaceproxy.h>
 
