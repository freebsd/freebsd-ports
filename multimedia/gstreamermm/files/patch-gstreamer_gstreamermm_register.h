--- gstreamer/gstreamermm/register.h.orig	2021-08-03 01:07:13 UTC
+++ gstreamer/gstreamermm/register.h
@@ -111,7 +111,7 @@ register_mm_type(const gchar * type_name)
      * system and whether the compiler is c++ or not. The g_once_init_*
      * functions always take a gsize * though ... */
     static volatile gsize gonce_data = 0;
-    if (g_once_init_enter (&gonce_data)) {
+    if (g_once_init_enter ((unsigned long *)&gonce_data)) {
         GTypeInfo info;
 
         info.class_size = sizeof(GlibCppTypeClass);
