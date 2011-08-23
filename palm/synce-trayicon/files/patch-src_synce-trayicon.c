--- src/synce-trayicon.c.orig	2011-08-16 14:13:49.000000000 +0200
+++ src/synce-trayicon.c	2011-08-16 14:14:40.000000000 +0200
@@ -204,7 +204,7 @@
   }
 
   if (gtk_status_icon_is_embedded(GTK_STATUS_ICON(self))) {
-          priv->notification = notify_notification_new_with_status_icon (summary, body, NULL, GTK_STATUS_ICON(self));
+          priv->notification = notify_notification_new (summary, body, NULL);
           notify_notification_show (priv->notification, NULL);
   } else {
           g_debug("%s: not embedded", G_STRFUNC);
