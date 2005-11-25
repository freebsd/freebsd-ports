--- src/muc.c.orig	Thu Nov 24 23:32:00 2005
+++ src/muc.c	Thu Nov 24 23:34:10 2005
@@ -1807,13 +1807,16 @@
 
 
 static void kf_muc_close (KfMUC *self) {
-	GtkWidget *win = gtk_message_dialog_new (GTK_WINDOW (self->window),
+	GtkWidget *win;
+	gint response;
+	
+	win = gtk_message_dialog_new (GTK_WINDOW (self->window),
 		GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
 		GTK_MESSAGE_QUESTION,
 		GTK_BUTTONS_OK_CANCEL,
 		_("Are you sure you want to leave this conference?"));
 	gtk_dialog_set_default_response (GTK_DIALOG (win), GTK_RESPONSE_CANCEL);
-	gint response = gtk_dialog_run (GTK_DIALOG (win));
+	response = gtk_dialog_run (GTK_DIALOG (win));
 	gtk_widget_destroy (win);
 	if (response == GTK_RESPONSE_OK)
 		gtk_widget_destroy (self->window);
