--- src/gpk-check-update.c.orig	2010-09-22 17:20:47.000000000 +0200
+++ src/gpk-check-update.c	2011-03-07 18:27:18.000000000 +0100
@@ -388,9 +388,8 @@ gpk_check_update_finished_notify (GpkChe
 	}
 
 	/* TRANSLATORS: title: system update completed all okay */
-	notification = notify_notification_new_with_status_icon (_("The system update has completed"),
-								 message_text->str, "help-browser",
-								 cupdate->priv->status_icon);
+	notification = notify_notification_new (_("The system update has completed"),
+						   message_text->str, "help-browser");
 	notify_notification_set_timeout (notification, 15000);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 	if (restart == PK_RESTART_ENUM_SYSTEM) {
@@ -456,7 +455,7 @@ gpk_check_update_show_error (GpkCheckUpd
 
 	/* do the bubble */
 	egg_debug ("title=%s, message=%s", title, message);
-	notification = notify_notification_new_with_status_icon (title, message, "help-browser", cupdate->priv->status_icon);
+	notification = notify_notification_new (title, message, "help-browser");
 	if (notification == NULL) {
 		egg_warning ("failed to get bubble");
 		goto out;
@@ -656,7 +655,7 @@ gpk_check_update_critical_updates_warnin
 
 	/* do the bubble */
 	egg_debug ("title=%s, message=%s", title, message);
-	notification = notify_notification_new_with_status_icon (title, message, "help-browser", cupdate->priv->status_icon);
+	notification = notify_notification_new (title, message, "help-browser");
 	if (notification == NULL) {
 		egg_warning ("failed to get bubble");
 		return;
@@ -782,9 +781,8 @@ gpk_check_update_check_on_battery (GpkCh
 	/* TRANSLATORS: policy says update, but we are on battery and so prompt */
 	message = _("Automatic updates are not being installed as the computer is running on battery power");
 	/* TRANSLATORS: informs user will not install by default */
-	notification = notify_notification_new_with_status_icon (_("Updates not installed"),
-								 message, "help-browser",
-								 cupdate->priv->status_icon);
+	notification = notify_notification_new (_("Updates not installed"),
+						   message, "help-browser");
 	notify_notification_set_timeout (notification, 15000);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 //	notify_notification_add_action (notification, "do-not-show-update-not-battery",
@@ -839,10 +837,10 @@ gpk_check_update_notify_doing_updates (G
 		goto out;
 
 	/* TRANSLATORS: title: notification when we scheduled an automatic update */
-	notification = notify_notification_new_with_status_icon (_("Updates are being installed"),
+	notification = notify_notification_new (_("Updates are being installed"),
 						/* TRANSLATORS: tell the user why the hard disk is grinding... */
 						_("Updates are being automatically installed on your computer"),
-						"software-update-urgent", cupdate->priv->status_icon);
+						"software-update-urgent");
 	notify_notification_set_timeout (notification, 15000);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 	/* TRANSLATORS: button: cancel the update system */
@@ -1328,7 +1326,7 @@ gpk_check_update_get_distro_upgrades_fin
 
 	/* TRANSLATORS: a distro update is available, e.g. Fedora 8 to Fedora 9 */
 	title = _("Distribution upgrades available");
-	notification = notify_notification_new_with_status_icon (title, string->str, "help-browser", cupdate->priv->status_icon);
+	notification = notify_notification_new (title, string->str, "help-browser");
 	if (notification == NULL) {
 		egg_warning ("failed to make bubble");
 		goto out;
