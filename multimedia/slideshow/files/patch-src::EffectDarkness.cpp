--- src/EffectDarkness.cpp.orig	Fri Nov 29 01:06:50 2002
+++ src/EffectDarkness.cpp	Fri Nov 29 01:07:20 2002
@@ -52,8 +52,8 @@
 	int   dt = screen->format->BytesPerPixel;
 	   
 	   // Sorry, work to do
-	   assert (ds == 4 || ds == 3);
-	   assert (dt == 4 || ds == 3);
+	   if (ds != 4 && ds != 3) return;
+	   if (dt != 4 && ds != 3) return;
 	   
 
 	   for (int i=0; i< parent_surface->w * parent_surface->h; i++) {
