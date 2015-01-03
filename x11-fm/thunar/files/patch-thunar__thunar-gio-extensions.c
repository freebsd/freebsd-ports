Add support for the GTK3 bookmarks file (bug #10627)

--- ./thunar/thunar-gio-extensions.c.orig	2013-05-05 16:37:23.000000000 +0000
+++ ./thunar/thunar-gio-extensions.c	2014-07-26 15:25:12.000000000 +0000
@@ -77,7 +77,7 @@
   gchar *filename;
   GFile *bookmarks;
 
-  filename = g_build_filename (xfce_get_homedir (), ".gtk-bookmarks", NULL);
+  filename = g_build_filename (g_get_user_config_dir (), "gtk-3.0", "bookmarks", NULL);
   bookmarks = g_file_new_for_path (filename);
   g_free (filename);
 
