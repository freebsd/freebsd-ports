--- libgnomeui/gnome-icon-lookup.c.orig	Thu Sep 18 02:13:50 2003
+++ libgnomeui/gnome-icon-lookup.c	Thu Sep 18 02:16:19 2003
@@ -107,6 +107,10 @@
 
   if (vfs_mime_name)
     {
+      /* Handle absolute files */
+      if (vfs_mime_name[0] == '/')
+        return g_strdup (vfs_mime_name);
+
       p = strrchr(vfs_mime_name, '.');
 
       if (p)
@@ -293,7 +297,9 @@
   if (mime_type)
     {
       mime_name = get_vfs_mime_name (mime_type);
-      if (mime_name && gnome_icon_theme_has_icon (icon_theme, mime_name))
+      if (mime_name &&
+	 ((mime_name[0] == '/' && g_file_test (mime_name, G_FILE_TEST_IS_REGULAR) ||
+	   gnome_icon_theme_has_icon (icon_theme, mime_name))))
 	return mime_name;
       g_free (mime_name);
       
