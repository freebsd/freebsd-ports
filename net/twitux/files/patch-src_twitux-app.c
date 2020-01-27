--- src/twitux-app.c.orig	2009-01-25 01:24:00 UTC
+++ src/twitux-app.c
@@ -1446,8 +1446,7 @@ twitux_app_notify (gchar *msg)
 
 		notification = notify_notification_new (PACKAGE_NAME,
 												msg,
-												"twitux",
-												NULL);
+												"twitux");
 
 		notify_notification_set_timeout (notification, 8 * 1000);
 		notify_notification_show (notification, &error);
