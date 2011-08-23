--- calendar/gui/alarm-notify/alarm-queue.c.orig	2011-03-07 20:53:40.000000000 +0100
+++ calendar/gui/alarm-notify/alarm-queue.c	2011-03-07 20:53:50.000000000 +0100
@@ -1606,7 +1606,7 @@ popup_notification (time_t trigger, Comp
 			body = g_strdup_printf ("%s %s", start_str, time_str);
 	}
 
-	n = notify_notification_new (summary, body, "stock_appointment-reminder", NULL);
+	n = notify_notification_new (summary, body, "stock_appointment-reminder");
 	if (!notify_notification_show(n, NULL))
 	    g_warning ("Could not send notification to daemon\n");
 
