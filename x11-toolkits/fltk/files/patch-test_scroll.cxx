--- test/scroll.cxx.orig	Sat Sep 22 13:33:34 2007
+++ test/scroll.cxx	Sat Sep 22 13:33:53 2007
@@ -71,7 +71,7 @@
 }
 
 void type_cb(Fl_Widget*, void* v) {
-  thescroll->type(int(v));
+  thescroll->type(long(v));
   thescroll->redraw();
 }
 
@@ -87,7 +87,7 @@
 };
 
 void align_cb(Fl_Widget*, void* v) {
-  thescroll->scrollbar.align(int(v));
+  thescroll->scrollbar.align(long(v));
   thescroll->redraw();
 }
 
