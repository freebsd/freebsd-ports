--- src/plugins/GUI/gui_chat.c.orig	Mon Jan  3 16:51:02 2005
+++ src/plugins/GUI/gui_chat.c	Fri Jan 28 00:23:27 2005
@@ -249,6 +249,7 @@
 
 void on_clear_clicked(GtkWidget * button, gpointer user_data)
 {
+	GtkTextBuffer *buf;
 	gint chat_type = (gint) ggadu_config_var_get(gui_handler, "chat_type");
 	gui_chat_session *session = NULL;
 	GtkWidget *textview = NULL;
@@ -267,7 +268,7 @@
 		textview = g_object_get_data(G_OBJECT(session->chat), "history");
 	}
 
-	GtkTextBuffer *buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
+	buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
 	gtk_text_buffer_set_text(buf, "", -1);
 }
 
