--- datatype/fo-color.c.orig	Thu Mar  3 10:50:38 2005
+++ datatype/fo-color.c	Thu Mar  3 10:51:09 2005
@@ -307,12 +307,13 @@
 			 guint blue)
 {
     FoDatatype *color = fo_color_new ();
+    FoDatatype *hashed_color;
 
     fo_color_set_red (color, red);
     fo_color_set_blue (color, blue);
     fo_color_set_green (color, green);
 
-    FoDatatype *hashed_color =
+    hashed_color =
 	(FoDatatype *) fo_hash_table_lookup (FO_COLOR_GET_CLASS(color)->colors,
 					     FO_OBJECT (color),
 					     NULL);
