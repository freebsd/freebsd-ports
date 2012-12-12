Index: src/Fl_x.cxx
===================================================================
--- src/Fl_x.cxx	(revision 9749)
+++ src/Fl_x.cxx	(working copy)
@@ -1873,7 +1873,7 @@
   // since we do not want save_under, do not want to turn off the
   // border, and cannot grab without an existing window. Besides, 
   // there is no clear_override(). 
-  if (win->flags() & Fl_Widget::FULLSCREEN && !Fl_X::ewmh_supported()) {
+  if (win->fullscreen_active() && !Fl_X::ewmh_supported()) {
     attr.override_redirect = 1;
     mask |= CWOverrideRedirect;
     Fl::screen_xywh(X, Y, W, H, X, Y, W, H);
@@ -1940,7 +1940,7 @@
     }
 
     // If asked for, create fullscreen
-    if (win->flags() & Fl_Widget::FULLSCREEN && Fl_X::ewmh_supported()) {
+    if (win->fullscreen_active() && Fl_X::ewmh_supported()) {
       XChangeProperty (fl_display, xp->xid, fl_NET_WM_STATE, XA_ATOM, 32,
                        PropModeAppend, (unsigned char*) &fl_NET_WM_STATE_FULLSCREEN, 1);
     }
@@ -1984,7 +1984,7 @@
   }
 
   // non-EWMH fullscreen case, need grab
-  if (win->flags() & Fl_Widget::FULLSCREEN && !Fl_X::ewmh_supported()) {
+  if (win->fullscreen_active() && !Fl_X::ewmh_supported()) {
     XGrabKeyboard(fl_display, xp->xid, 1, GrabModeAsync, GrabModeAsync, fl_event_time);
   }
