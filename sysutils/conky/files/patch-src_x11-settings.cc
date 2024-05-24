--- src/x11-settings.cc.orig	2024-05-19 17:48:45 UTC
+++ src/x11-settings.cc
@@ -77,7 +77,7 @@ bool use_xpmdb_setting::set_up(lua::state &l) {
   if (!out_to_x.get(l)) return false;
 
   window.back_buffer =
-      XCreatePixmap(display, window.window, window.geometry.get_width() + 1, window.geometry.get_height() + 1,
+      XCreatePixmap(display, window.window, window.geometry.width() + 1, window.geometry.height() + 1,
                     DefaultDepth(display, screen));
   if (window.back_buffer != None) {
     window.drawable = window.back_buffer;
