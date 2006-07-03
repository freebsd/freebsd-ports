--- lm/src/matherr.c.orig	Fri Jul 29 11:29:51 2005
+++ lm/src/matherr.c	Mon Jul  3 15:16:58 2006
@@ -18,13 +18,6 @@
 matherr(struct exception *x)
 #endif
 {
-    if (x->type == SING && strcmp(x->name, "log10") == 0) {
-	/*
-	 * suppress warnings about log10(0.0)
-	 */
-	return 1;
-    } else {
 	return 0;
-    }
 }
 
