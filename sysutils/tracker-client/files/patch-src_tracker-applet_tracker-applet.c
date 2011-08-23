--- src/tracker-applet/tracker-applet.c.orig	2011-08-16 14:59:30.000000000 +0200
+++ src/tracker-applet/tracker-applet.c	2011-08-16 15:00:25.000000000 +0200
@@ -2074,10 +2074,9 @@ tray_icon_show_message (TrayIcon    *ico
 	}
 
 	notification =
-		notify_notification_new_with_status_icon ("Tracker",
+		notify_notification_new ("Tracker",
 							  msg,
-							  NULL,
-							  priv->icon);
+							  NULL);
 
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_NORMAL);
 	notify_notification_show (notification, NULL);
@@ -2125,10 +2124,9 @@ tray_icon_show_error (TrayIcon    *icon,
 	va_end (args);
 
 	error_notification =
-		notify_notification_new_with_status_icon ("Tracker",
+		notify_notification_new ("Tracker",
 							  msg,
-							  NULL,
-							  priv->icon);
+							  NULL);
 
         notify_notification_set_timeout (error_notification, NOTIFY_EXPIRES_NEVER);
 	notify_notification_set_urgency (error_notification, NOTIFY_URGENCY_CRITICAL);
