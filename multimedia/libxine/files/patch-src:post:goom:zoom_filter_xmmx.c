--- src/post/goom/zoom_filter_xmmx.c.orig	Sun May  9 22:41:34 2004
+++ src/post/goom/zoom_filter_xmmx.c	Sun May  9 22:51:42 2004
@@ -124,7 +124,7 @@
 				"andl $15,%%eax\n"
 
 				"movd (%%ebx,%%eax,4),%%mm3\n"
-				::"X"(precalCoef):"eax","ebx");
+				::"g"(precalCoef):"eax","ebx");
 
 			/*
 			 * extraction des coefficients...
