--- src/flist-mime-icon.c.orig	Wed May 29 03:31:00 2002
+++ src/flist-mime-icon.c	Fri Jun 14 21:24:00 2002
@@ -132,7 +132,7 @@
 const char *
 flist_mime_get_icon (const char *mime_type)
 {
-  gchar *mime_part, *index, *icon_name, *icon_name2;
+  gchar *mime_part, *index, *icon_name, *icon_name2, *icon_name3;
 
   if (!mime_type)
     goto skip_theme_stuff;
@@ -170,6 +170,19 @@
   
  skip_theme_stuff:
   
+  mime_part = g_strdup (mime_type);
+  index = strchr (mime_part, '/');
+  *index = '-';
+
+  icon_name3 = g_strconcat (MIMEICONDIR, "document-icons/gnome-", mime_part, ".png", NULL);
+
+  g_free(mime_part);
+
+  if (g_file_exists (icon_name3))
+    return icon_name3;
+    
+  g_free (icon_name3);
+
   return gnome_vfs_mime_get_icon (mime_type);
 }
 
@@ -218,6 +231,9 @@
 	if (!file) {
 	  if (!icon) return NULL;
 	  flist_nautilus_theme_load ();
+
+          if (!strstr(icon, ".png"))
+             icon = g_strconcat(icon, ".png", NULL);
 
 	  if (!g_file_exists (icon)) {
 	    if (nautilus_theme_dir) file = g_concat_dir_and_file (nautilus_theme_dir, icon);
