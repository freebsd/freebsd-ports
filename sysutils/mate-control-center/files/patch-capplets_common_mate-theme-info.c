--- capplets/common/mate-theme-info.c.orig	2009-05-03 20:30:56.000000000 +0200
+++ capplets/common/mate-theme-info.c	2009-07-19 12:54:25.000000000 +0200
@@ -1876,7 +1876,7 @@ mate_theme_init ()
 #ifdef XCURSOR_ICONDIR
   /* if there's a separate xcursors dir, add that as well */
   if (strcmp (XCURSOR_ICONDIR, top_theme_dir_string) &&
-      strcmp (XCURSOR_ICONDIR, "/usr/share/icons")) {
+      strcmp (XCURSOR_ICONDIR, "%%LOCALBASE%%/share/icons")) {
     top_theme_dir = g_file_new_for_path (XCURSOR_ICONDIR);
     add_top_icon_theme_dir_monitor (top_theme_dir, 1, NULL);
     g_object_unref (top_theme_dir);
