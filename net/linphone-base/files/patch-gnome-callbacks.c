--- gnome/callbacks.c.orig	Sat Jul  9 22:32:24 2005
+++ gnome/callbacks.c	Thu Aug 25 23:44:43 2005
@@ -595,9 +595,10 @@
                                         gpointer         user_data)
 {
 	gchar *sipurl;
+	GtkWidget *gcr;
 	
 	sipurl=gtk_editable_get_chars(GTK_EDITABLE(get_main_window()->addressentry),0,-1);
-	GtkWidget *gcr=chatroom_new(sipurl,NULL);
+	gcr=chatroom_new(sipurl,NULL);
 	if (gcr!=NULL) gtk_widget_show(gcr);
 	g_free(sipurl);
 }
