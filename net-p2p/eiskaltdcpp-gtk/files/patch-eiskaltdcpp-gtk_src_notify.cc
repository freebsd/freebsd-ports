--- eiskaltdcpp-gtk/src/notify.cc.orig	2011-08-12 11:54:13.000000000 +0200
+++ eiskaltdcpp-gtk/src/notify.cc	2011-08-12 11:54:24.000000000 +0200
@@ -69,7 +69,7 @@ void Notify::init()
 {
 #ifdef USE_LIBNOTIFY
 	notify_init(g_get_application_name());
-	notification = notify_notification_new("template", "template", NULL, NULL);
+	notification = notify_notification_new("template", "template", NULL);
 #endif // USE_LIBNOTIFY
 	action = FALSE;
 }
