--- texk/xdvik/pk.c.orig	2009-03-02 21:43:37 UTC
+++ texk/xdvik/pk.c
@@ -201,6 +201,9 @@ read_PK_char(struct font *fontp,
 
     g->dvi_adv = fontp->dimconv * fpwidth;
 
+#ifdef PTEX
+    g->tdir = fontp->dir;
+#endif /* PTEX */
     if (globals.debug & DBG_PK) {
 	if (g->bitmap.w != 0)
 	    printf(", size=%dx%d, dvi_adv=%ld", g->bitmap.w, g->bitmap.h,
