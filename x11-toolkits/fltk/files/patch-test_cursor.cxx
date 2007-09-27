--- test/cursor.cxx.orig	Fri Apr 15 20:13:17 2005
+++ test/cursor.cxx	Thu Sep 27 12:42:14 2007
@@ -39,7 +39,7 @@
 Fl_Hor_Value_Slider *cursor_slider;
 
 void choice_cb(Fl_Widget *, void *v) {
-  cursor = (Fl_Cursor)(int)v;
+  cursor = (Fl_Cursor)(long)v;
   cursor_slider->value(cursor);
   fl_cursor(cursor,fg,bg);
 }
