--- glib/glib_os_hnd.c.orig	2015-06-25 22:51:39.000000000 +0000
+++ glib/glib_os_hnd.c	2018-07-30 13:30:17.799255000 +0000
@@ -777,23 +777,21 @@
 {
     gint64 now;
     
-    now = g_get_monotonic_time();
-    tv->tv_sec = now / G_TIME_SPAN_SECOND;
-    tv->tv_usec = now % G_TIME_SPAN_SECOND;
+    g_get_current_time(&now);
+    tv->tv_sec = now / 1000000;
+    tv->tv_usec = now % 1000000;
     return 0;
 }
 
 static int get_glib_time(os_handler_t *handler,
 			 struct timeval *tv)
 {
-    GDateTime *now;
+    GTimeVal now;
     GTimeVal gtv;
     
-    now = g_date_time_new_now_utc();
-    g_date_time_to_timeval(now, &gtv);
-    g_date_time_unref(now);
-    tv->tv_sec = gtv.tv_sec;
-    tv->tv_usec = gtv.tv_usec;
+    g_get_current_time(&now);
+    tv->tv_sec = now.tv_sec;
+    tv->tv_usec = now.tv_usec;
     return 0;
 }
 
