--- src/x11.cc.orig	2024-05-19 17:48:25 UTC
+++ src/x11.cc
@@ -1219,10 +1219,10 @@ void xpmdb_swap_buffers(void) {
 void xpmdb_swap_buffers(void) {
   if (use_xpmdb.get(*state)) {
     XCopyArea(display, window.back_buffer, window.window, window.gc, 0, 0,
-              window.geometry.get_width(), window.geometry.get_height(), 0, 0);
+              window.geometry.width(), window.geometry.height(), 0, 0);
     XSetForeground(display, window.gc, 0);
-    XFillRectangle(display, window.drawable, window.gc, 0, 0, window.geometry.get_width(),
-                   window.geometry.get_height());
+    XFillRectangle(display, window.drawable, window.gc, 0, 0, window.geometry.width(),
+                   window.geometry.height());
     XFlush(display);
   }
 }
