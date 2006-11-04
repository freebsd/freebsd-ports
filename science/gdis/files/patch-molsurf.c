--- molsurf.c.orig	Mon Jun 19 17:42:29 2006
+++ molsurf.c	Wed Nov  1 23:55:43 2006
@@ -745,7 +745,7 @@
 gdouble Dx, Dy, Dz; 			/* gradient */
 gdouble temp[3]; 			/* the dreaded temporary variable */
 gdouble theta, sinTheta, cosTheta;
-gfloat hue, red, green, blue;
+gfloat hue, red, green, blue, colourRange, hueStep;
 time_t jobStartTime;
 
 #if DEBUG_SHAPE 
@@ -761,9 +761,7 @@
 #endif
 	
 	/* setup for colours */
-    gfloat colourRange= 256;
-    gfloat hueStep;
-    
+    colourRange= 256;
     hueStep = 240/colourRange;
 	
 	
