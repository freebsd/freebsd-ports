--- distributed_ls/pilut/parilut.c.orig	2021-11-07 12:05:55 UTC
+++ distributed_ls/pilut/parilut.c
@@ -145,7 +145,7 @@ void hypre_ParILUT(DataDistType *ddist, FactorMatType 
              newperm, newiperm, vrowdist, -1);*/
   hypre_TFree(jr, HYPRE_MEMORY_HOST);
   hypre_TFree(jw, HYPRE_MEMORY_HOST);
-  hypre_TFree(lr, HYPRE_MEMORY_HOST);
+  hypre_TFree(hypre_lr, HYPRE_MEMORY_HOST);
   hypre_TFree(w, HYPRE_MEMORY_HOST);
   hypre_TFree(pilut_map, HYPRE_MEMORY_HOST);
   hypre_TFree(nrmat.rmat_rnz, HYPRE_MEMORY_HOST);
@@ -167,7 +167,7 @@ void hypre_ParILUT(DataDistType *ddist, FactorMatType 
 
   jr = NULL;
   jw = NULL;
-  lr = NULL;
+  hypre_lr = NULL;
   w  = NULL;
 
 #ifdef HYPRE_DEBUG
@@ -651,9 +651,9 @@ void hypre_ComputeRmat(FactorMatType *ldu, ReduceMatTy
       /* record L elements */
       if (IsInMIS(pilut_map[rcolind[lastjr]])) {
          if (rcolind[lastjr] >= firstrow  &&  rcolind[lastjr] < lastrow)
-            lr[lastlr] = (newiperm[rcolind[lastjr]-firstrow] << 1);
+            hypre_lr[lastlr] = (newiperm[rcolind[lastjr]-firstrow] << 1);
          else {
-            lr[lastlr] = pilut_map[rcolind[lastjr]];  /* map[] == (l<<1) | 1 */
+            hypre_lr[lastlr] = pilut_map[rcolind[lastjr]];  /* map[] == (l<<1) | 1 */
             hypre_assert(incolind[StripMIS(pilut_map[rcolind[lastjr]])+1] ==
                  rcolind[lastjr]);
          }
@@ -696,7 +696,7 @@ void hypre_ComputeRmat(FactorMatType *ldu, ReduceMatTy
             /* record L elements -- these must be local */
             if (IsInMIS(pilut_map[ucolind[l]])) {
                hypre_assert(ucolind[l] >= firstrow  &&  ucolind[l] < lastrow);
-               lr[lastlr] = (newiperm[ucolind[l]-firstrow] << 1);
+               hypre_lr[lastlr] = (newiperm[ucolind[l]-firstrow] << 1);
                lastlr++;
             }
 
@@ -736,7 +736,7 @@ void hypre_ComputeRmat(FactorMatType *ldu, ReduceMatTy
             /* record L elements -- these must be remote */
             if (IsInMIS(pilut_map[incolind[l]])) {
                hypre_assert(incolind[l] < firstrow  ||  incolind[l] >= lastrow);
-               lr[lastlr] = pilut_map[incolind[l]];  /* map[] == (l<<1) | 1 */
+               hypre_lr[lastlr] = pilut_map[incolind[l]];  /* map[] == (l<<1) | 1 */
                lastlr++;
             }
 
@@ -834,7 +834,7 @@ void hypre_FactorLocal(FactorMatType *ldu, ReduceMatTy
       if (rcolind[lastjr] >= firstrow  &&
             rcolind[lastjr] <  lastrow   &&
             newiperm[rcolind[lastjr]-firstrow] < diag) {
-         lr[lastlr] = newiperm[rcolind[lastjr]-firstrow];
+         hypre_lr[lastlr] = newiperm[rcolind[lastjr]-firstrow];
         lastlr++;
       }
 
@@ -873,7 +873,7 @@ void hypre_FactorLocal(FactorMatType *ldu, ReduceMatTy
                   ucolind[l] <  lastrow   &&
                   newiperm[ucolind[l]-firstrow] < diag) {
                hypre_assert(IsInMIS(pilut_map[ucolind[l]]));
-               lr[lastlr] = newiperm[ucolind[l]-firstrow];
+               hypre_lr[lastlr] = newiperm[ucolind[l]-firstrow];
                lastlr++;
             }
 
@@ -1353,8 +1353,8 @@ void hypre_ParINIT( ReduceMatType *nrmat, CommInfoType
   /* Allocate work space */
   hypre_TFree(jr, HYPRE_MEMORY_HOST);
   jr = hypre_idx_malloc_init(nrows, -1, "hypre_ParILUT: jr");
-  hypre_TFree(lr, HYPRE_MEMORY_HOST);
-  lr = hypre_idx_malloc_init(nleft, -1, "hypre_ParILUT: lr");
+  hypre_TFree(hypre_lr, HYPRE_MEMORY_HOST);
+  hypre_lr = hypre_idx_malloc_init(nleft, -1, "hypre_ParILUT: lr");
   hypre_TFree(jw, HYPRE_MEMORY_HOST);
   jw = hypre_idx_malloc(nleft, "hypre_ParILUT: jw");
   hypre_TFree(w, HYPRE_MEMORY_HOST);
