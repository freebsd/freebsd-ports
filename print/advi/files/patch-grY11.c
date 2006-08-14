--- grY11.c.orig	Sun Aug 13 01:16:56 2006
+++ grY11.c	Sun Aug 13 01:17:06 2006
@@ -473,7 +473,7 @@
   return Val_unit;
 }
 
-value caml_gr_resize_window (value wid, value w, value h)
+value caml_gr_resize_window1 (value wid, value w, value h)
 {
   Window win;
 
