--- src/twitux-app.c.orig	2011-08-16 15:27:29.000000000 +0200
+++ src/twitux-app.c	2011-08-16 15:27:54.000000000 +0200
@@ -1446,8 +1446,7 @@ twitux_app_notify (gchar *msg)
 
 		notification = notify_notification_new (PACKAGE_NAME,
 												msg,
-												"twitux",
-												NULL);
+												"twitux");
 
 		notify_notification_set_timeout (notification, 8 * 1000);
 		notify_notification_show (notification, &error);
