--- plugins/publish-calendar/publish-calendar.c.orig	2011-03-07 21:12:59.000000000 +0100
+++ plugins/publish-calendar/publish-calendar.c	2011-03-07 21:14:23.000000000 +0100
@@ -150,8 +150,7 @@ update_publish_notification (GtkMessageT
 				return;
 			}
 
-			notify  = notify_notification_new (_("Calendar Publishing"), actual_msg->str, stock_name, NULL);
-			notify_notification_attach_to_status_icon (notify, status_icon);
+			notify  = notify_notification_new (_("Calendar Publishing"), actual_msg->str, stock_name);
 			notify_notification_set_urgency (notify, NOTIFY_URGENCY_NORMAL);
 			notify_notification_set_timeout (notify, NOTIFY_EXPIRES_DEFAULT);
 			g_timeout_add (500, show_notify_cb, NULL);
