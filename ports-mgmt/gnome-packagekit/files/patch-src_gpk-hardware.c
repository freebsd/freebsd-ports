--- src/gpk-hardware.c.orig	2011-03-07 18:21:23.000000000 +0100
+++ src/gpk-hardware.c	2011-03-07 18:21:32.000000000 +0100
@@ -183,7 +183,7 @@ gpk_hardware_what_provides_cb (GObject *
 	message = g_strdup_printf ("%s\n\t%s", _("Additional packages can be installed to support this hardware"), package);
 	/* TRANSLATORS: a new bit of hardware has been plugged in */
 	body = g_strdup_printf ("%s", _("New hardware attached"));
-	notification = notify_notification_new (body, message, "help-browser", NULL);
+	notification = notify_notification_new (body, message, "help-browser");
 	notify_notification_set_timeout (notification, NOTIFY_EXPIRES_NEVER);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 	notify_notification_add_action (notification, GPK_HARDWARE_INSTALL_ACTION,
