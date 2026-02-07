--- uigtk2.ml.orig	2014-12-30 02:21:28 UTC
+++ uigtk2.ml
@@ -89,12 +89,12 @@ let icon =
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
 
 let leftPtrWatch =
