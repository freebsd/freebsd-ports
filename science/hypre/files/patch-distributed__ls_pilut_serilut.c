--- distributed_ls/pilut/serilut.c.orig	2021-11-07 12:06:04 UTC
+++ distributed_ls/pilut/serilut.c
@@ -70,8 +70,8 @@ HYPRE_Int hypre_SerILUT(DataDistType *ddist, HYPRE_Dis
   /* Allocate work space */
   hypre_TFree(jr, HYPRE_MEMORY_HOST);
   jr = hypre_idx_malloc_init(nrows, -1, "hypre_SerILUT: jr");
-  hypre_TFree(lr, HYPRE_MEMORY_HOST);
-  lr = hypre_idx_malloc_init(nrows, -1, "hypre_SerILUT: lr");
+  hypre_TFree(hypre_lr, HYPRE_MEMORY_HOST);
+  hypre_lr = hypre_idx_malloc_init(nrows, -1, "hypre_SerILUT: lr");
   hypre_TFree(jw, HYPRE_MEMORY_HOST);
   jw = hypre_idx_malloc(nrows, "hypre_SerILUT: jw");
   hypre_TFree(w, HYPRE_MEMORY_HOST);
@@ -158,7 +158,7 @@ HYPRE_Int hypre_SerILUT(DataDistType *ddist, HYPRE_Dis
 
     for (lastjr=1, lastlr=0, j=0, diag_present=0; j<row_size; j++) {
       if (iperm[ col_ind[j] - firstrow ] < iperm[i]) 
-        lr[lastlr++] = iperm[ col_ind[j]-firstrow]; /* Copy the L elements separately */
+        hypre_lr[lastlr++] = iperm[ col_ind[j]-firstrow]; /* Copy the L elements separately */
 
       if (col_ind[j] != i+firstrow) { /* Off-diagonal element */
         jr[col_ind[j]] = lastjr;
@@ -207,7 +207,7 @@ HYPRE_Int hypre_SerILUT(DataDistType *ddist, HYPRE_Dis
 
         if (m == -1) {  /* Create fill */
           if (iperm[ucolind[l]-firstrow] < iperm[i]) 
-            lr[lastlr++] = iperm[ucolind[l]-firstrow]; /* Copy the L elements separately */
+            hypre_lr[lastlr++] = iperm[ucolind[l]-firstrow]; /* Copy the L elements separately */
 
           jr[ucolind[l]] = lastjr;
           jw[lastjr] = ucolind[l];
@@ -258,7 +258,7 @@ HYPRE_Int hypre_SerILUT(DataDistType *ddist, HYPRE_Dis
       if (col_ind[j] >= firstrow  &&
             col_ind[j] < lastrow    &&
             iperm[col_ind[j]-firstrow] < nlocal) 
-        lr[lastlr++] = iperm[col_ind[j]-firstrow]; /* Copy the L elements separately */
+        hypre_lr[lastlr++] = iperm[col_ind[j]-firstrow]; /* Copy the L elements separately */
 
       if (col_ind[j] != i+firstrow) { /* Off-diagonal element */
         jr[col_ind[j]] = lastjr;
@@ -304,7 +304,7 @@ HYPRE_Int hypre_SerILUT(DataDistType *ddist, HYPRE_Dis
         if (m == -1) {  /* Create fill */
            hypre_CheckBounds(firstrow, ucolind[l], lastrow, globals);
           if (iperm[ucolind[l]-firstrow] < nlocal) 
-            lr[lastlr++] = iperm[ucolind[l]-firstrow]; /* Copy the L elements separately */
+            hypre_lr[lastlr++] = iperm[ucolind[l]-firstrow]; /* Copy the L elements separately */
 
           jr[ucolind[l]] = lastjr;
           jw[lastjr] = ucolind[l];
@@ -330,11 +330,11 @@ HYPRE_Int hypre_SerILUT(DataDistType *ddist, HYPRE_Dis
   /*hypre_free_multi(jr, jw, lr, w, -1);*/
   hypre_TFree(jr, HYPRE_MEMORY_HOST);
   hypre_TFree(jw, HYPRE_MEMORY_HOST);
-  hypre_TFree(lr, HYPRE_MEMORY_HOST);
+  hypre_TFree(hypre_lr, HYPRE_MEMORY_HOST);
   hypre_TFree(w, HYPRE_MEMORY_HOST);
   jr = NULL;
   jw = NULL;
-  lr = NULL;
+  hypre_lr = NULL;
   w = NULL;
 
   return(ierr);
