--- capplets/common/mate-theme-info.c.orig	2017-05-28 07:59:23 UTC
+++ capplets/common/mate-theme-info.c
@@ -1819,7 +1819,7 @@ mate_theme_init ()
 
   /* if there's a separate xcursors dir, add that as well */
   if (strcmp (XCURSOR_ICONDIR, top_theme_dir_string) &&
-      strcmp (XCURSOR_ICONDIR, "/usr/share/icons")) {
+      strcmp (XCURSOR_ICONDIR, "%%LOCALBASE%%/share/icons")) {
     top_theme_dir = g_file_new_for_path (XCURSOR_ICONDIR);
     add_top_icon_theme_dir_monitor (top_theme_dir, 1, NULL);
     g_object_unref (top_theme_dir);
