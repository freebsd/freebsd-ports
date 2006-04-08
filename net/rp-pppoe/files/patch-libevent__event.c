--- libevent/event.c.orig	Sat Apr  8 16:15:20 2006
+++ libevent/event.c	Sat Apr  8 16:15:50 2006
@@ -86,9 +86,6 @@
 
     struct timeval abs_timeout, now;
 
-    /* Avoid compiler warning */
-    abs_timeout.tv_sec = 0;
-    abs_timeout.tv_usec = 0;
     struct timeval timeout;
     struct timeval *tm;
     EventHandler *eh;
@@ -100,6 +97,10 @@
     int foundWriteEvent = 0;
     int maxfd = -1;
     int pastDue;
+
+    /* Avoid compiler warning */
+    abs_timeout.tv_sec = 0;
+    abs_timeout.tv_usec = 0;
 
     EVENT_DEBUG(("Enter Event_HandleEvent(es=%p)\n", (void *) es));
 
