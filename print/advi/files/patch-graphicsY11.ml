--- graphicsY11.ml.orig	Sun Aug 13 01:17:58 2006
+++ graphicsY11.ml	Sun Aug 13 01:18:03 2006
@@ -109,7 +109,7 @@
     = "caml_gr_move_window";;
 
 external raw_resize_window : window_id -> int -> int -> unit
-    = "caml_gr_resize_window";;
+    = "caml_gr_resize_window1";;
 
 let resize_subwindow wid height width =
   if wid != null_window then begin 
