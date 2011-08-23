--- src/empathy-chat-window.c.orig	2011-08-16 16:23:38.000000000 +0200
+++ src/empathy-chat-window.c	2011-08-16 16:24:00.000000000 +0200
@@ -1300,7 +1300,7 @@ chat_window_show_or_update_notification 
 		   to an existing notification with the same title.
 		   In this way the previous message will not be lost: the new
 		   message will appear below it, in the same notification */
-		notification = notify_notification_new (header, escaped, NULL, NULL);
+		notification = notify_notification_new (header, escaped, NULL);
 
 		if (priv->notification == NULL) {
 			priv->notification = notification;
