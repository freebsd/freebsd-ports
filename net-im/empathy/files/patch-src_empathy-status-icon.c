--- src/empathy-status-icon.c.orig	2011-08-16 16:25:07.000000000 +0200
+++ src/empathy-status-icon.c	2011-08-16 16:25:32.000000000 +0200
@@ -206,8 +206,8 @@ status_icon_update_notification (Empathy
 			   to an existing notification with the same title.
 			   In this way the previous message will not be lost: the new
 			   message will appear below it, in the same notification */
-			notification = notify_notification_new_with_status_icon
-				(priv->event->header, message_esc, NULL, priv->icon);
+			notification = notify_notification_new
+				(priv->event->header, message_esc, NULL);
 
 			if (priv->notification == NULL) {
 				priv->notification = notification;
