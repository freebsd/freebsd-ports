--- beep/main.c.orig	Sat Nov 15 21:33:27 2003
+++ beep/main.c	Sat Nov 15 21:35:22 2003
@@ -1634,7 +1634,7 @@
 
 	if (treeview->selection)
 	{
-		pos = gtk_treeview_get_row_data(treeview, GPOINTER_TO_INT(treeview->selection->data));
+//		pos = gtk_treeview_get_row_data(treeview, GPOINTER_TO_INT(treeview->selection->data));
 		playlist_queue_position(*pos);
 		gtk_widget_set(GTK_WIDGET(widget), "label", playlist_is_position_queued(*pos) ? "Unqueue" : "Queue", NULL);
 	}	
@@ -2030,11 +2030,12 @@
 		
 
 		if (!strncasecmp(path,"fonts:///",9)) {
+				gchar * decoded;
 				path[strlen(path)-2] = 0; /* Why the hell a CR&LF? */
 				path = path + 8;
 
 				/* plain, since we already stripped the first URI part */
-				gchar * decoded = xmms_urldecode_plain(path);
+				decoded = xmms_urldecode_plain(path);
 				decoded++;
 
 				/* Get the old font's size, and add it to the dropped font's name */
