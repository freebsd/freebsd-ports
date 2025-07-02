--- BLACS/SRC/blacs_init_.c.orig	2024-08-06 11:44:11 UTC
+++ BLACS/SRC/blacs_init_.c
@@ -6,7 +6,12 @@ F_VOID_FUNC blacs_gridinit_(Int *ConTxt, F_CHAR order,
 F_VOID_FUNC blacs_gridinit_(Int *ConTxt, F_CHAR order, Int *nprow, Int *npcol)
 #endif
 {
+#if (INTFACE == C_CALL)
    void Cblacs_gridmap(Int *, Int *, Int, Int, Int);
+#else
+   F_VOID_FUNC blacs_gridmap_(Int *ConTxt, Int *usermap, Int *ldup, Int *nprow0,
+                              Int *npcol0);
+#endif
    Int *tmpgrid, *iptr;
    Int i, j;
 
