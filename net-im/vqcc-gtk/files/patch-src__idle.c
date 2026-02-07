--- src/idle.c.orig	2005-01-03 20:36:55 UTC
+++ src/idle.c
@@ -54,6 +54,12 @@ idle_check_cb(gpointer dummy)
 idle_check_cb(gpointer dummy)
 {
 	unsigned idle_time; /* idle time in minutes */
+#ifndef _WIN32
+ #ifdef USE_XSCREENSAVER
+	static XScreenSaverInfo * xss_info = 0;
+	int event_base, error_base;
+ #endif /* #ifdef USE_XSCREENSAVER */
+#endif
 
 	/* do not enter auto-away or auto-offline when we're in invisible mode */
 	if(my_mode()==UMODE_INVISIBLE)
@@ -63,8 +69,6 @@ idle_check_cb(gpointer dummy)
 	idle_time = winvqcc_get_last_active() / 60000;
 #else
 #ifdef USE_XSCREENSAVER
-	static XScreenSaverInfo * xss_info = 0;
-	int event_base, error_base;
 
 	/* Query X Window System XScreenSaver extension
 	 */
