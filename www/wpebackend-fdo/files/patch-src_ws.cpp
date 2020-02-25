https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=243677
https://github.com/Igalia/WPEBackend-fdo/issues/94

--- src/ws.cpp.orig	2020-02-21 16:15:02.984298000 +0100
+++ src/ws.cpp	2020-02-21 16:15:37.982114000 +0100
@@ -112,7 +112,7 @@
 
         if (source.pfd.revents & G_IO_IN) {
             struct wl_event_loop* eventLoop = wl_display_get_event_loop(source.display);
-            wl_event_loop_dispatch(eventLoop, -1);
+            wl_event_loop_dispatch(eventLoop, 0);
             wl_display_flush_clients(source.display);
         }
 
