--- capplets/common/gnome-theme-info.c.orig	2008-05-17 12:46:59.000000000 -0400
+++ capplets/common/gnome-theme-info.c	2008-05-20 18:10:50.000000000 -0400
@@ -1843,7 +1843,7 @@ gnome_theme_init ()
   g_object_unref (top_theme_dir);
 
   /* The weird /usr/share/icons */
-  top_theme_dir = g_file_new_for_path ("/usr/share/icons");
+  top_theme_dir = g_file_new_for_path ("%%LOCALBASE%%/lib/X11/icons");
   add_top_icon_theme_dir_monitor (top_theme_dir, 2, NULL);
   g_object_unref (top_theme_dir);
 
@@ -1857,7 +1857,7 @@ gnome_theme_init ()
 #ifdef XCURSOR_ICONDIR
   /* if there's a separate xcursors dir, add that as well */
   if (strcmp (XCURSOR_ICONDIR, top_theme_dir_string) &&
-      strcmp (XCURSOR_ICONDIR, "/usr/share/icons")) {
+      strcmp (XCURSOR_ICONDIR, "%%LOCALBASE%%/lib/X11/icons")) {
     top_theme_dir = g_file_new_for_path (XCURSOR_ICONDIR);
     if (g_file_query_exists (top_theme_dir, NULL))
       add_top_icon_theme_dir_monitor (top_theme_dir, 1, NULL);
