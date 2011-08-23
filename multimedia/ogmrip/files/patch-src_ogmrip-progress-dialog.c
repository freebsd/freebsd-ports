--- src/ogmrip-progress-dialog.c.orig	2011-08-12 13:44:15.000000000 +0200
+++ src/ogmrip-progress-dialog.c	2011-08-12 14:16:35.000000000 +0200
@@ -418,8 +418,8 @@ ogmrip_progress_dialog_init (OGMRipProgr
   g_signal_connect_swapped (dialog->priv->status_icon, "popup_menu",
       G_CALLBACK (ogmrip_progress_dialog_status_icon_popup_menu), dialog);
 
-  dialog->priv->notification = notify_notification_new_with_status_icon ("Dummy", "Dummy",
-      OGMRIP_DATA_DIR G_DIR_SEPARATOR_S OGMRIP_ICON_FILE, dialog->priv->status_icon);
+  dialog->priv->notification = notify_notification_new ("Dummy", "Dummy",
+      OGMRIP_DATA_DIR G_DIR_SEPARATOR_S OGMRIP_ICON_FILE);
   g_signal_connect (dialog, "window-state-event",
       G_CALLBACK (ogmrip_progress_dialog_state_changed), NULL);
 
