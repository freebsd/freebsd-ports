--- capplets/common/gnome-theme-info.c.orig	2007-10-30 18:58:26.000000000 -0400
+++ capplets/common/gnome-theme-info.c	2007-11-01 08:43:25.067405773 -0400
@@ -661,7 +661,7 @@
     theme_info->thumbnail = gdk_pixbuf_new_from_file (filename, NULL);
     g_free (filename);
 
-    theme_info->path = g_build_filename (GNOMECC_DATA_DIR, builtins[i][0], NULL);
+    theme_info->name = g_build_filename (INSTALL_PREFIX, "share", builtins[i][0], NULL);
     theme_info->name = g_strdup (theme_info->path);
 
     if (!strcmp (theme_info->path, cursor_font))
@@ -1922,7 +1922,7 @@
   gnome_vfs_uri_unref (top_theme_dir_uri);
 
   /* The weird /usr/share/icons */
-  top_theme_dir_uri = gnome_vfs_uri_new ("/usr/share/icons");
+  top_theme_dir_uri = gnome_vfs_uri_new ("%%LOCALBASE%%/lib/X11/icons");
   if (!gnome_vfs_uri_exists (top_theme_dir_uri))
     gnome_vfs_make_directory_for_uri (top_theme_dir_uri, 0775);
   add_top_icon_theme_dir_monitor (top_theme_dir_uri, &real_monitor_not_added, 2, NULL);
