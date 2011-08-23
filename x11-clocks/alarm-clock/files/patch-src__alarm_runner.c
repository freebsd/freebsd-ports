--- src/alarm_runner.c.orig	2011-08-12 17:00:32.000000000 +0200
+++ src/alarm_runner.c	2011-08-12 17:01:09.000000000 +0200
@@ -210,7 +210,7 @@ show_popup(gchar *name)
 	text = g_key_file_get_string(loaded_alarms, name, "PassivePopupText", NULL);
 	
 	if (notify != NULL) notify_notification_close(notify, NULL);
-	notify = notify_notification_new_with_status_icon(title, text, NULL, status_icon);
+	notify = notify_notification_new(title, text, NULL);
 	
 	notify_notification_set_urgency(notify, type);
 	notify_notification_set_timeout(notify, timeout * 1000);
