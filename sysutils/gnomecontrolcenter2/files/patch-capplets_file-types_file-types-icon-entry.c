--- capplets/file-types/file-types-icon-entry.c.orig	Sun May  5 16:33:51 2002
+++ capplets/file-types/file-types-icon-entry.c	Sun May  5 16:34:02 2002
@@ -424,7 +424,7 @@
 	result = NULL;
 	filename = nautilus_mime_type_icon_entry_get_full_filename (NAUTILUS_MIME_ICON_ENTRY (ientry));
 	if (filename != NULL) {
-		path_parts = g_strsplit (filename, "/share/pixmaps/", 0);
+		path_parts = g_strsplit (filename, "/share/gnome/pixmaps/", 0);
 		g_free (filename);
 
 		if (path_parts[1] != NULL) {
