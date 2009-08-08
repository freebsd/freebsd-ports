--- gst-libs/gst/video/gstbasevideoutils.c.orig	2009-08-08 11:53:34.000000000 +0200
+++ gst-libs/gst/video/gstbasevideoutils.c	2009-08-08 11:53:58.000000000 +0200
@@ -229,7 +229,7 @@ scan_slow (GstAdapter *adapter, GSList *
   return ((GST_READ_UINT32_BE (tmp) & mask) == pattern);
 }
 
-
+/*
 int
 gst_adapter_masked_scan_uint32 (GstAdapter *adapter,
     guint32 pattern, guint32 mask, int offset, int n)
@@ -271,6 +271,7 @@ gst_adapter_masked_scan_uint32 (GstAdapt
 
   return n;
 }
+*/
 
 GstBuffer *
 gst_adapter_get_buffer (GstAdapter *adapter)
