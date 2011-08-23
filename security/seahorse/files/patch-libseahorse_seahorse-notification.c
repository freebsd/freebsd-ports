--- libseahorse/seahorse-notification.c.orig	2011-03-06 21:03:39.000000000 +0100
+++ libseahorse/seahorse-notification.c	2011-03-06 21:03:58.000000000 +0100
@@ -231,7 +231,7 @@ setup_libnotify_notification (SeahorseNo
     heading = format_key_text (snotif->heading);
     message = format_key_text (snotif->message);
     
-    notif = notify_notification_new (heading, message, snotif->icon, attachto);
+    notif = notify_notification_new (heading, message, snotif->icon);
     
     g_free (heading);
     g_free (message);
