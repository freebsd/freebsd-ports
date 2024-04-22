--- src/kernel/LinAlg_SPARSKIT.cpp.orig	2024-03-08 06:48:58 UTC
+++ src/kernel/LinAlg_SPARSKIT.cpp
@@ -117,7 +117,7 @@ void LinAlg_CreateVector(gVector *V, gSolver *Solver, 
   V->N = n;
 }
 
-void LinAlg_CreateMatrix(gMatrix *M, gSolver *Solver, int n, int m)
+void LinAlg_CreateMatrix(gMatrix *M, gSolver *Solver, int n, int m, bool silent)
 {
   init_matrix(n, &M->M, &Solver->Params);
 }
