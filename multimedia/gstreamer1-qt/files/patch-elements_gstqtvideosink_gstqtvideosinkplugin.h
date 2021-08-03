--- elements/gstqtvideosink/gstqtvideosinkplugin.h.orig	2021-08-03 00:05:38 UTC
+++ elements/gstqtvideosink/gstqtvideosinkplugin.h
@@ -28,7 +28,7 @@ GST_DEBUG_CATEGORY_EXTERN(gst_qt_video_sink_debug);
     GType cpp_type::get_type() \
     { \
         static volatile gsize gonce_data = 0; \
-        if (g_once_init_enter(&gonce_data)) { \
+        if (g_once_init_enter((unsigned long *)&gonce_data)) { \
             GType type = 0; \
             GTypeInfo info; \
             info.class_size = sizeof(cpp_type##Class); \
