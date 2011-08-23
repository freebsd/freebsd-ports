--- src/ggn-icon.c.orig	2011-08-16 13:36:23.000000000 +0200
+++ src/ggn-icon.c	2011-08-16 13:37:27.000000000 +0200
@@ -566,12 +566,7 @@ gpointer ggn_icon_show_notification_thre
   /* create a new notification. */
   icon->priv->note = notify_notification_new (icon->priv->title,
                                               icon->priv->summary,
-                                              icon->priv->icon_file,
-                                              NULL);
-
-  /* attach the notification to our icon. */
-  notify_notification_attach_to_status_icon (icon->priv->note,
-                                             icon->priv->icon);
+                                              icon->priv->icon_file);
 
   /* set the notification timeout. */
   notify_notification_set_timeout (icon->priv->note, (4 * 1000));
