--- src/gui/main.cpp.orig	2011-03-08 22:31:52.000000000 +0100
+++ src/gui/main.cpp	2011-03-08 22:47:35.000000000 +0100
@@ -2807,12 +2807,11 @@ ekiga_main_window_incoming_call_notify (
 
   body = g_strdup_printf ("%s\n%s\n%s", uri, app, account);
   
-  notify = notify_notification_new (title, body, GM_ICON_LOGO, NULL);
+  notify = notify_notification_new (title, body, GM_ICON_LOGO);
   notify_notification_add_action (notify, "accept", _("Accept"), notify_action_cb, mw, NULL);
   notify_notification_add_action (notify, "reject", _("Reject"), notify_action_cb, mw, NULL);
   notify_notification_set_timeout (notify, NOTIFY_EXPIRES_NEVER);
   notify_notification_set_urgency (notify, NOTIFY_URGENCY_CRITICAL);
-  notify_notification_attach_to_status_icon (notify, statusicon);
   if (!notify_notification_show (notify, NULL)) {
     ekiga_main_window_incoming_call_dialog_show (mw, call);
   }
