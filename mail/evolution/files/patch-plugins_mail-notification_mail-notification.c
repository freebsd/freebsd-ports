--- plugins/mail-notification/mail-notification.c.orig	2011-03-07 21:24:25.000000000 +0100
+++ plugins/mail-notification/mail-notification.c	2011-03-07 21:24:40.000000000 +0100
@@ -564,9 +564,7 @@ new_notify_status (EMEventTargetFolder *
 
 			notify  = notify_notification_new (
 				_("New email"), safetext,
-				"mail-unread", NULL);
-			notify_notification_attach_to_status_icon (
-				notify, status_icon);
+				"mail-unread");
 
 			/* Check if actions are supported */
 			if (can_support_actions ()) {
