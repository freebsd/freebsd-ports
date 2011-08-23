--- src/xfpm-notify.c.orig	2011-02-15 21:52:35.000000000 +0100
+++ src/xfpm-notify.c	2011-08-14 10:44:28.000000000 +0200
@@ -233,9 +233,6 @@ xfpm_notify_new_notification_internal (c
 #if !NOTIFY_CHECK_VERSION (0, 7, 0) 
     if ( icon )
     	notify_notification_attach_to_status_icon (n, icon);
-#else
-    if ( icon )
-    	notify_notification_attach_to_status_icon (n, icon);
 #endif
 #endif
 	
