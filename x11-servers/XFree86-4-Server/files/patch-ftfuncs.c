--- lib/font/FreeType/ftfuncs.c~	2003-02-13 06:01:45.000000000 +0300
+++ lib/font/FreeType/ftfuncs.c	2003-03-04 20:27:16.000000000 +0300
@@ -959,11 +959,11 @@
         int underlinePosition, underlineThickness;
 
         if(post) {
-            underlinePosition = TRANSFORM_FUNITS_Y(post->underlinePosition);
+            underlinePosition = TRANSFORM_FUNITS_Y(-post->underlinePosition);
             underlineThickness = TRANSFORM_FUNITS_Y(post->underlineThickness);
         } else {
             underlinePosition = 
-                TRANSFORM_FUNITS_Y(t1info->underline_position);
+                TRANSFORM_FUNITS_Y(-t1info->underline_position);
             underlineThickness = 
                 TRANSFORM_FUNITS_Y(t1info->underline_thickness);
         }