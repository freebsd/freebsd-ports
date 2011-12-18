--- lib/libXDAAP/ioloop.c.orig
+++ lib/libXDAAP/ioloop.c
@@ -122,9 +122,9 @@
 
 void fd_event_reset(fd_event *event)
 {
-    event->signalled = 0;
     char buf[1] = {0};
     int flags;
+    event->signalled = 0;
 
     /* set non-blocking on read pipe */
     flags = fcntl(event->pipe[0], F_GETFL, 0);
