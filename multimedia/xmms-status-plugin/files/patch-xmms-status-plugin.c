--- src/xmms-status-plugin.c.orig	Wed Mar  5 21:47:55 2003
+++ src/xmms-status-plugin.c	Wed Jan 10 19:17:22 2007
@@ -440,7 +440,7 @@
 					 guint               info,
 					 guint               time)
 {
-	xmms_remote_playlist_add_url_string(status_plugin.xmms_session, selection_data->data);
+	xmms_remote_playlist_add_url_string(status_plugin.xmms_session, (gchar *)selection_data->data);
 
 	gtk_drag_finish (context, TRUE, FALSE, time);
 }
