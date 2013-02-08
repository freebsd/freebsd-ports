--- ./src/misc/parole-file.c.orig	2013-01-07 10:15:53.000000000 +0000
+++ ./src/misc/parole-file.c	2013-01-08 21:14:23.000000000 +0000
@@ -610,7 +610,11 @@
 void
 parole_file_set_custom_subtitles (const ParoleFile *file, gchar *suburi)
 {
+#if GLIB_CHECK_VERSION (2, 30, 0)
     GValue value = G_VALUE_INIT;
+#else
+    GValue value;
+#endif
     g_value_init (&value, G_TYPE_STRING);
     g_value_set_static_string (&value, suburi);
     
@@ -643,7 +647,11 @@
 void
 parole_file_set_dvd_chapter (const ParoleFile *file, gint dvd_chapter)
 {
+#if GLIB_CHECK_VERSION (2, 30, 0)
     GValue value = G_VALUE_INIT;
+#else
+    GValue value;
+#endif
     g_value_init (&value, G_TYPE_INT);
     g_value_set_int (&value, dvd_chapter);
     
