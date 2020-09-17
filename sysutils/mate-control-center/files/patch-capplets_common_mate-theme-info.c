--- capplets/common/mate-theme-info.c.orig	2020-08-15 13:10:32 UTC
+++ capplets/common/mate-theme-info.c
@@ -1824,7 +1824,7 @@ mate_theme_init ()
   g_strfreev (search_path);
 
   /* if there's a separate xcursors dir, add that as well */
-  if (strcmp (XCURSOR_ICONDIR, "/usr/share/icons")) {
+  if (strcmp (XCURSOR_ICONDIR, "%%LOCALBASE%%/share/icons")) {
     top_theme_dir = g_file_new_for_path (XCURSOR_ICONDIR);
     add_top_icon_theme_dir_monitor (top_theme_dir, 1, NULL);
     g_object_unref (top_theme_dir);
