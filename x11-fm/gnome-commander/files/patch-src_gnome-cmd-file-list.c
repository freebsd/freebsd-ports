--- src/gnome-cmd-file-list.c.orig	2007-12-07 01:55:47.000000000 +0100
+++ src/gnome-cmd-file-list.c	2007-12-07 01:58:30.000000000 +0100
@@ -57,7 +57,7 @@
 };
 
 
-static GtkTargetEntry drag_types [] = {
+GtkTargetEntry drag_types [] = {
 	{ TARGET_URI_LIST_TYPE, 0, TARGET_URI_LIST },
 	{ TARGET_TEXT_PLAIN_TYPE, 0, TARGET_TEXT_PLAIN },
 	{ TARGET_URL_TYPE, 0, TARGET_URL }
@@ -574,7 +574,7 @@
 	switch (info){
 		case TARGET_URI_LIST:
 		case TARGET_TEXT_PLAIN:
-			gtk_selection_data_set (selection_data, selection_data->target, 8, data, len);
+			gtk_selection_data_set (selection_data, selection_data->target, 8, (guchar *)data, len);
 			break;
 
 		case TARGET_URL:
