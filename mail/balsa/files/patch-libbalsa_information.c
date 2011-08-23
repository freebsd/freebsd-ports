--- libbalsa/information.c.orig	2011-08-16 13:30:24.000000000 +0200
+++ libbalsa/information.c	2011-08-16 13:30:48.000000000 +0200
@@ -122,7 +122,7 @@ libbalsa_information_varg(GtkWindow *par
         g_free(msg);
 
         note =
-            notify_notification_new("Balsa", escaped->str, icon_str, NULL);
+            notify_notification_new("Balsa", escaped->str, icon_str);
         g_string_free(escaped, TRUE);
 
         notify_notification_set_timeout(note, 7000);    /* 7 seconds */
