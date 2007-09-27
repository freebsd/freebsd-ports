--- test/line_style.cxx.orig	Sat Sep 22 12:55:42 2007
+++ test/line_style.cxx	Sat Sep 22 12:56:25 2007
@@ -54,9 +54,9 @@
   buf[3] = char(sliders[7]->value());
   buf[4] = 0;
   fl_line_style(
-    (int)(choice[0]->mvalue()->user_data()) +
-    (int)(choice[1]->mvalue()->user_data()) +
-    (int)(choice[2]->mvalue()->user_data()),
+    (long)(choice[0]->mvalue()->user_data()) +
+    (long)(choice[1]->mvalue()->user_data()) +
+    (long)(choice[2]->mvalue()->user_data()),
     (int)(sliders[3]->value()),
     buf);
   fl_rect(10,10,w()-20,h()-20);
