--- src/gpm-manager.c.orig	2011-03-07 12:49:54.000000000 +0100
+++ src/gpm-manager.c	2011-03-07 12:51:08.000000000 +0100
@@ -481,11 +481,7 @@ gpm_manager_notify (GpmManager *manager,
 	gpm_manager_notify_close (manager, *notification_class);
 
 	/* if the status icon is hidden, don't point at it */
-	if (manager->priv->status_icon != NULL &&
-	    gtk_status_icon_is_embedded (manager->priv->status_icon))
-		notification = notify_notification_new_with_status_icon (title, message, icon, manager->priv->status_icon);
-	else
-		notification = notify_notification_new (title, message, icon, NULL);
+		notification = notify_notification_new (title, message, icon);
 	notify_notification_set_timeout (notification, timeout);
 	notify_notification_set_urgency (notification, urgency);
 	g_signal_connect (notification, "closed", G_CALLBACK (gpm_manager_notification_closed_cb), notification_class);
