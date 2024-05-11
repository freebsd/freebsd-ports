--- src/x11.cc.orig	2024-05-14 16:06:21 UTC
+++ src/x11.cc
@@ -1215,10 +1215,10 @@ void xpmdb_swap_buffers(void) {
 void xpmdb_swap_buffers(void) {
   if (use_xpmdb.get(*state)) {
     XCopyArea(display, window.back_buffer, window.window, window.gc, 0, 0,
-              window.width, window.height, 0, 0);
+              window.geometry.get_width(), window.geometry.get_height(), 0, 0);
     XSetForeground(display, window.gc, 0);
-    XFillRectangle(display, window.drawable, window.gc, 0, 0, window.width,
-                   window.height);
+    XFillRectangle(display, window.drawable, window.gc, 0, 0, window.geometry.get_width(),
+                   window.geometry.get_height());
     XFlush(display);
   }
 }
