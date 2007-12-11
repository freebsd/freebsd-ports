--- src/gnome-cmd-file-selector.c.orig	2007-12-07 01:59:14.000000000 +0100
+++ src/gnome-cmd-file-selector.c	2007-12-07 02:00:52.000000000 +0100
@@ -42,7 +42,7 @@
 
 #define AUTOSCROLL_INTERVAL 100
 
-static GtkTargetEntry drop_types [] = {
+GtkTargetEntry drop_types [] = {
 	{ TARGET_URI_LIST_TYPE, 0, TARGET_URI_LIST },
 	{ TARGET_URL_TYPE, 0, TARGET_URL }
 };
@@ -405,7 +405,7 @@
 	/* Transform the drag data to a list with uris
 	 *
 	 */
-	uri_list = strings_to_uris (selection_data->data);
+	uri_list = strings_to_uris ((gchar *)selection_data->data);
 
 	if (g_list_length (uri_list) == 1) {
 		GnomeVFSURI *uri = (GnomeVFSURI*)uri_list->data;
