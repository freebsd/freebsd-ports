--- src/stickynotes.c.orig	Mon Feb 17 17:55:56 2003
+++ src/stickynotes.c	Mon Feb 17 17:58:02 2003
@@ -39,6 +39,9 @@
 StickyNote * stickynote_new()
 {
 	StickyNote *note;
+	GtkWidget *title_box;
+	GtkWidget *resize_box;
+	GtkWidget *close_box;
 	
 	/* Create and initialize a Sticky Note */
 	note = g_new(StickyNote, 1);
@@ -47,9 +50,9 @@
 	note->title = glade_xml_get_widget(note->glade, "title_label");
 	note->body = glade_xml_get_widget(note->glade, "body_text");
 
-	GtkWidget *title_box = glade_xml_get_widget(note->glade, "title_box");
-	GtkWidget *resize_box = glade_xml_get_widget(note->glade, "resize_box");
-	GtkWidget *close_box = glade_xml_get_widget(note->glade, "close_box");
+	title_box = glade_xml_get_widget(note->glade, "title_box");
+	resize_box = glade_xml_get_widget(note->glade, "resize_box");
+	close_box = glade_xml_get_widget(note->glade, "close_box");
 	
 	/* Add the note to the linked-list of all notes */
 	stickynotes->notes = g_list_append(stickynotes->notes, note);
@@ -364,9 +367,10 @@
 			{
 				gchar *title0 = gconf_client_get_string(stickynotes->gconf_client, GCONF_PATH "/settings/date_format", NULL);
 				gchar *title1 = xmlGetProp(node, "title");
+				gchar *title2;
 				if (!title1)
 					title1 = get_current_date(title0);
-				gchar *title2 = g_strdup_printf("<b>%s</b>", title1);
+				title2 = g_strdup_printf("<b>%s</b>", title1);
 				gtk_label_set_markup(GTK_LABEL(note->title), title2);
 				g_free(title0);
 				g_free(title1);
