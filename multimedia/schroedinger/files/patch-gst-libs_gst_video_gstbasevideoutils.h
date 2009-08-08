--- gst-libs/gst/video/gstbasevideoutils.h.orig	2009-08-08 11:53:39.000000000 +0200
+++ gst-libs/gst/video/gstbasevideoutils.h	2009-08-08 11:54:07.000000000 +0200
@@ -84,8 +84,10 @@ gboolean gst_base_video_state_from_caps 
 GstClockTime gst_video_state_get_timestamp (const GstVideoState *state,
     int frame_number);
 
+/*
 int gst_adapter_masked_scan_uint32 (GstAdapter *adapter,
     guint32 pattern, guint32 mask, int offset, int n);
+*/
 GstBuffer *gst_adapter_get_buffer (GstAdapter *adapter);
 
 G_END_DECLS
