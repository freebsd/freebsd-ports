--- src/plugins/GUI/GUI_plugin.c.orig	Fri Jun 11 03:25:33 2004
+++ src/plugins/GUI/GUI_plugin.c	Wed Jul 21 22:42:19 2004
@@ -753,6 +753,7 @@
 	GGaduMsg *msg = signal->data;
 	gui_protocol *gp = NULL;
 	gchar *soundfile = NULL;
+	GtkWidget *window;
 
 	if (!signal || !msg)
 	{
@@ -816,7 +817,7 @@
 	        if (msg->message && (soundfile = ggadu_config_var_get(gui_handler, "sound_msg_in")))
 		        signal_emit_full("main-gui", "sound play file", soundfile, "sound*", NULL);
             
-			GtkWidget *window = gtk_widget_get_ancestor(session->chat, GTK_TYPE_WINDOW);
+			window = gtk_widget_get_ancestor(session->chat, GTK_TYPE_WINDOW);
 		        if (!GTK_WIDGET_VISIBLE(window)) {
 				if (showwindow) {
 /*				    GtkWidget *input = g_object_get_data(G_OBJECT(session->chat), "input");
