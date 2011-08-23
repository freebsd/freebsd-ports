--- libseahorse/seahorse-notification.c.orig	2011-03-07 09:25:10.000000000 +0100
+++ libseahorse/seahorse-notification.c	2011-03-07 09:25:57.000000000 +0100
@@ -213,7 +213,7 @@
     heading = format_key_text (snotif->heading);
     message = format_key_text (snotif->message);
     
-    notif = notify_notification_new (heading, message, snotif->icon, attachto);
+    notif = notify_notification_new (heading, message, snotif->icon);
     
     g_free (heading);
     g_free (message);
