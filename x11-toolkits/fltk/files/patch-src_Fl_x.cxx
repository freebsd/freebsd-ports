--- src/Fl_x.cxx.orig	2011-11-28 10:52:26.000000000 +0100
+++ src/Fl_x.cxx	2011-11-28 11:01:42.000000000 +0100
@@ -1858,7 +1858,7 @@
     prop[1] = 1|2|16; // MWM_FUNC_ALL | MWM_FUNC_RESIZE | MWM_FUNC_MAXIMIZE
   }
 
-  if (w->flags() & Fl_Widget::FORCE_POSITION) {
+  if (w->force_position()) {
     hints->flags |= USPosition;
     hints->x = w->x();
     hints->y = w->y();
