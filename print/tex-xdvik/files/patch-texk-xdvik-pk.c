--- texk/xdvik/pk.c.orig	2014-09-02 18:41:34.000000000 +0900
+++ texk/xdvik/pk.c	2015-01-31 21:02:18.000000000 +0900
@@ -201,6 +201,9 @@
 
     g->dvi_adv = fontp->dimconv * fpwidth;
 
+#ifdef PTEX
+    g->tdir = fontp->dir;
+#endif /* PTEX */
     if (globals.debug & DBG_PK) {
 	if (g->bitmap.w != 0)
 	    printf(", size=%dx%d, dvi_adv=%ld", g->bitmap.w, g->bitmap.h,
