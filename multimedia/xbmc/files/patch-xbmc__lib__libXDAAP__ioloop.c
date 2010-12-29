--- ./xbmc/lib/libXDAAP/ioloop.c.orig	2008-08-10 17:07:47.000000000 +0200
+++ ./xbmc/lib/libXDAAP/ioloop.c	2010-12-01 12:17:34.240824916 +0100
@@ -122,9 +122,9 @@
 
 void fd_event_reset(fd_event *event)
 {
-    event->signalled = 0;
     char buf[1] = {0};
     int flags;
+    event->signalled = 0;
 
     /* set non-blocking on read pipe */
     flags = fcntl(event->pipe[0], F_GETFL, 0);
