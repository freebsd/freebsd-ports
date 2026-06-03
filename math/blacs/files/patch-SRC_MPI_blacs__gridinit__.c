--- SRC/MPI/blacs_gridinit_.c.orig	2006-01-18 21:36:03 UTC
+++ SRC/MPI/blacs_gridinit_.c
@@ -6,7 +6,12 @@ F_VOID_FUNC blacs_gridinit_(int *ConTxt, F_CHAR order,
 F_VOID_FUNC blacs_gridinit_(int *ConTxt, F_CHAR order, int *nprow, int *npcol)
 #endif
 {
+#if (INTFACE == C_CALL)
    void Cblacs_gridmap(int *, int *, int, int, int);
+#else
+   F_VOID_FUNC blacs_gridmap_(int *ConTxt, int *usermap, int *ldup, int *nprow0,
+                              int *npcol0);
+#endif
    int *tmpgrid, *iptr;
    int i, j;
 
