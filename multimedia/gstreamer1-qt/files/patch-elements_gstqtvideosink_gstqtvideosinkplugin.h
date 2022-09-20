--- elements/gstqtvideosink/gstqtvideosinkplugin.h.orig	2014-07-08 18:38:36 UTC
+++ elements/gstqtvideosink/gstqtvideosinkplugin.h
@@ -27,8 +27,8 @@ GST_DEBUG_CATEGORY_EXTERN(gst_qt_video_sink_debug);
 #define DEFINE_TYPE_FULL(cpp_type, type_name, parent_type, additional_initializations) \
     GType cpp_type::get_type() \
     { \
-        static volatile gsize gonce_data = 0; \
-        if (g_once_init_enter(&gonce_data)) { \
+        static gsize gonce_data = 0; \
+        if (g_once_init_enter((unsigned long *)&gonce_data)) { \
             GType type = 0; \
             GTypeInfo info; \
             info.class_size = sizeof(cpp_type##Class); \
