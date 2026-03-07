Adaptations for GStreamer 1.28.1

--- gst-libs/gst/vaapi/gstvaapidecoder_h265.c.orig	2025-12-25 14:44:26 UTC
+++ gst-libs/gst/vaapi/gstvaapidecoder_h265.c
@@ -456,7 +456,7 @@ nal_is_irap (guint8 nal_type)
 nal_is_irap (guint8 nal_type)
 {
   if ((nal_type >= GST_H265_NAL_SLICE_BLA_W_LP) &&
-      (nal_type <= RESERVED_IRAP_NAL_TYPE_MAX))
+      (nal_type <= GST_H265_RESERVED_IRAP_NAL_TYPE_MAX))
     return TRUE;
   return FALSE;
 }
