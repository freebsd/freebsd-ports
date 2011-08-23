--- src/gpk-watch.c.orig	2010-09-22 17:20:31.000000000 +0200
+++ src/gpk-watch.c	2011-03-07 09:32:41.000000000 +0100
@@ -1153,7 +1153,7 @@ gpk_watch_process_messages_cb (PkMessage
 	}
 
 	/* do the bubble */
-	notification = notify_notification_new_with_status_icon (gpk_message_enum_to_localised_text (type), details, "emblem-important", watch->priv->status_icon);
+	notification = notify_notification_new (gpk_message_enum_to_localised_text (type), details, "emblem-important");
 	notify_notification_set_timeout (notification, NOTIFY_EXPIRES_NEVER);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 	ret = notify_notification_show (notification, &error);
@@ -1213,7 +1213,7 @@ gpk_watch_process_error_code (GpkWatch *
 	title_prefix = g_strdup_printf ("%s: %s", _("Package Manager"), title);
 
 	/* do the bubble */
-	notification = notify_notification_new (title_prefix, message, "help-browser", NULL);
+	notification = notify_notification_new (title_prefix, message, "help-browser");
 	notify_notification_set_timeout (notification, 15000);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 	notify_notification_add_action (notification, "show-error-details",
@@ -1392,7 +1392,7 @@ gpk_watch_adopt_cb (PkClient *client, GA
 		goto out;
 
 	/* TRANSLATORS: title: an action has finished, and we are showing the libnotify bubble */
-	notification = notify_notification_new (_("Task completed"), message, "help-browser", NULL);
+	notification = notify_notification_new (_("Task completed"), message, "help-browser");
 	notify_notification_set_timeout (notification, 5000);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 	notify_notification_add_action (notification, "do-not-show-notify-complete",
