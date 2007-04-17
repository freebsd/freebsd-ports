--- gtk/callbacks.c.orig	Wed Feb  7 18:11:10 2007
+++ gtk/callbacks.c	Fri Apr 13 03:42:46 2007
@@ -626,9 +626,10 @@
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
