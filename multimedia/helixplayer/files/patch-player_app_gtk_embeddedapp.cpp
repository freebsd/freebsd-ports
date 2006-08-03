--- player/app/gtk/embeddedapp.cpp	Tue Dec  7 16:17:19 2004
+++ player/app/gtk/embeddedapp.cpp	Sun Jul  2 02:55:03 2006
@@ -80,4 +80,7 @@
 
 #include <glib.h>
+#if GLIB_CHECK_VERSION (2, 4, 0)
+# define g_value_set_string_take_ownership	g_value_take_string
+#endif
 
 /* This file contains functions with several different prefixes.
@@ -276,5 +279,5 @@
 typedef struct
 {
-    guint stream_id;
+    uintptr_t stream_id;
     HXDataStream* stream;
     gchar* url;
@@ -3108,5 +3111,5 @@
 
 HXEmbeddedWindow*
-hxembedded_window_get_from_id(guint window_id)
+hxembedded_window_get_from_id(uintptr_t window_id)
 {
     GList* consoles_iter;
@@ -3165,5 +3168,5 @@
 void
 hxembedded_window_new_stream(HXEmbeddedWindow* window,
-                             guint stream_id,
+                             uintptr_t stream_id,
                              const gchar* url,
                              const gchar* mime_type,
@@ -3296,5 +3299,5 @@
 void
 hxembedded_window_stream_done(HXEmbeddedWindow* window,
-                              guint stream_id)
+                              uintptr_t stream_id)
 {
     GList* iter;
