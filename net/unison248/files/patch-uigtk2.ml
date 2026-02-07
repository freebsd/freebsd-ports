--- uigtk2.ml.orig	2009-05-14 15:59:33 UTC
+++ uigtk2.ml
@@ -93,12 +93,12 @@ let fontMonospaceMediumPango = lazy (Pango.Font.from_s
 (* This does not work with the current version of Lablgtk, due to a bug
 let icon =
   GdkPixbuf.from_data ~width:48 ~height:48 ~has_alpha:true
-    (Gpointer.region_of_string Pixmaps.icon_data)
+    (Gpointer.region_of_bytes Pixmaps.icon_data)
 *)
 let icon =
   let p = GdkPixbuf.create ~width:48 ~height:48 ~has_alpha:true () in
   Gpointer.blit
-    (Gpointer.region_of_string Pixmaps.icon_data) (GdkPixbuf.get_pixels p);
+    (Gpointer.region_of_bytes Pixmaps.icon_data) (GdkPixbuf.get_pixels p);
   p
 
 (*********************************************************************
