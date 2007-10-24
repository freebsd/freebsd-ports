--- capplets/common/gnome-theme-info.c.orig	2007-08-27 04:09:06.000000000 -0400
+++ capplets/common/gnome-theme-info.c	2007-09-20 15:24:56.000000000 -0400
@@ -1845,7 +1845,7 @@ read_cursor_fonts (void)
     theme_info->thumbnail = gdk_pixbuf_new_from_file (filename, NULL);
     g_free (filename);
 
-    theme_info->name = g_build_filename (GNOMECC_DATA_DIR, builtins[i][0], NULL);
+    theme_info->name = g_build_filename (INSTALL_PREFIX, "share", builtins[i][0], NULL);
     theme_info->path = g_strdup (theme_info->name);
 
     if (!strcmp (theme_info->path, cursor_font))
@@ -1974,7 +1974,7 @@ gnome_theme_init (gboolean *monitor_not_
   gnome_vfs_uri_unref (top_theme_dir_uri);
 
   /* The weird /usr/share/icons */
-  top_theme_dir_uri = gnome_vfs_uri_new ("/usr/share/icons");
+  top_theme_dir_uri = gnome_vfs_uri_new ("%%LOCALBASE%%/lib/X11/icons");
   if (!gnome_vfs_uri_exists (top_theme_dir_uri))
     gnome_vfs_make_directory_for_uri (top_theme_dir_uri, 0775);
   result = add_top_icon_theme_dir_monitor (top_theme_dir_uri, &real_monitor_not_added, 2, NULL);
