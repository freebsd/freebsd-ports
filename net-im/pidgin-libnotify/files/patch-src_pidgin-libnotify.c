--- src/pidgin-libnotify.c.orig	2011-08-12 15:51:55.000000000 +0200
+++ src/pidgin-libnotify.c	2011-08-12 15:53:28.000000000 +0200
@@ -286,7 +286,7 @@
 		g_free (tr_body);
 		return;
 	}
-	notification = notify_notification_new (title, tr_body, NULL, NULL);
+	notification = notify_notification_new (title, tr_body, NULL);
 	purple_debug_info (PLUGIN_ID, "notify(), new: "
 					 "title: '%s', body: '%s', buddy: '%s'\n",
 					 title, tr_body, best_name (buddy));
