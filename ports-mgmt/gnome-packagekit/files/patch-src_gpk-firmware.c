--- src/gpk-firmware.c.orig	2011-03-07 18:20:16.000000000 +0100
+++ src/gpk-firmware.c	2011-03-07 18:20:38.000000000 +0100
@@ -268,7 +268,7 @@ gpk_firmware_require_restart (GpkFirmwar
 	message = _("You will need to restart this computer before the hardware will work correctly.");
 
 	/* TRANSLATORS: title of libnotify bubble */
-	notification = notify_notification_new (_("Additional software was installed"), message, "help-browser", NULL);
+	notification = notify_notification_new (_("Additional software was installed"), message, "help-browser");
 	notify_notification_set_timeout (notification, NOTIFY_EXPIRES_NEVER);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 
@@ -303,7 +303,7 @@ gpk_firmware_require_replug (GpkFirmware
 	message = _("You will need to remove and then reinsert the hardware before it will work correctly.");
 
 	/* TRANSLATORS: title of libnotify bubble */
-	notification = notify_notification_new (_("Additional software was installed"), message, "help-browser", NULL);
+	notification = notify_notification_new (_("Additional software was installed"), message, "help-browser");
 	notify_notification_set_timeout (notification, NOTIFY_EXPIRES_NEVER);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 
@@ -330,7 +330,7 @@ gpk_firmware_require_nothing (GpkFirmwar
 	message = _("Your hardware has been set up and is now ready to use.");
 
 	/* TRANSLATORS: title of libnotify bubble */
-	notification = notify_notification_new (_("Additional software was installed"), message, "help-browser", NULL);
+	notification = notify_notification_new (_("Additional software was installed"), message, "help-browser");
 	notify_notification_set_timeout (notification, NOTIFY_EXPIRES_NEVER);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 
@@ -624,7 +624,7 @@ gpk_firmware_timeout_cb (gpointer data)
 	}
 
 	/* TRANSLATORS: title of libnotify bubble */
-	notification = notify_notification_new (_("Additional firmware required"), string->str, "help-browser", NULL);
+	notification = notify_notification_new (_("Additional firmware required"), string->str, "help-browser");
 	notify_notification_set_timeout (notification, NOTIFY_EXPIRES_NEVER);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 	notify_notification_add_action (notification, "install-firmware",
