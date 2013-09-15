--- src/freebsd/up-devd.c.orig	2013-09-15 13:08:35.000000000 -0400
+++ src/freebsd/up-devd.c	2013-09-15 13:10:13.000000000 -0400
@@ -195,7 +195,7 @@ up_devd_event_cb (GIOChannel *source, GI
 		event[terminator] = 0;
 		up_devd_process_event(event, user_data);
 		g_free(event);
-	} else if (status == G_IO_STATUS_AGAIN) {
+	} else {
 		up_devd_init (UP_BACKEND(user_data));
 		if (up_devd_inited) {
 			int fd;
