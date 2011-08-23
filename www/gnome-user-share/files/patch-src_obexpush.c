--- src/obexpush.c.orig	2011-03-07 20:11:04.000000000 +0100
+++ src/obexpush.c	2011-03-07 20:11:34.000000000 +0100
@@ -139,10 +139,9 @@
 	/* Translators: %s is the name of the filename received */
 	notification_text = g_strdup_printf(_("You received \"%s\" via Bluetooth"), display);
 	g_free (display);
-	notification = notify_notification_new_with_status_icon (_("You received a file"),
+	notification = notify_notification_new (_("You received a file"),
 								 notification_text,
-								 "dialog-information",
-								 GTK_STATUS_ICON (statusicon));
+								 "dialog-information");
 
 	notify_notification_set_timeout (notification, NOTIFY_EXPIRES_DEFAULT);
 
