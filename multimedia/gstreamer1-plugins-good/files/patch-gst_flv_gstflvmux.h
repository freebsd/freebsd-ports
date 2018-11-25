--- gst/flv/gstflvmux.h.orig	2018-11-19 01:46:19 UTC
+++ gst/flv/gstflvmux.h
@@ -37,7 +37,6 @@ G_BEGIN_DECLS
 #define GST_IS_FLV_MUX_PAD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_FLV_MUX_PAD))
 
 typedef struct _GstFlvMuxPad GstFlvMuxPad;
-typedef struct _GstFlvMuxPadClass GstFlvMuxPadClass;
 
 #define GST_TYPE_FLV_MUX \
   (gst_flv_mux_get_type ())
