--- src/gpk-dbus-task.c.orig	2011-03-07 18:28:01.000000000 +0100
+++ src/gpk-dbus-task.c	2011-03-07 18:28:10.000000000 +0100
@@ -377,7 +377,7 @@ gpk_dbus_task_handle_error (GpkDbusTask 
 	dtask->priv->cached_error_code = g_object_ref (error_code);
 
 	/* do the bubble */
-	notification = notify_notification_new (title, message, "help-browser", NULL);
+	notification = notify_notification_new (title, message, "help-browser");
 	notify_notification_set_timeout (notification, 15000);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 	notify_notification_add_action (notification, "show-error-details",
