--- distributed_ls/pilut/HYPRE_DistributedMatrixPilutSolver.c.orig	2021-11-07 12:02:36 UTC
+++ distributed_ls/pilut/HYPRE_DistributedMatrixPilutSolver.c
@@ -39,7 +39,7 @@ HYPRE_Int  HYPRE_NewDistributedMatrixPilutSolver( 
        (hypre_PilutSolverGlobals *) hypre_CTAlloc( hypre_PilutSolverGlobals,  1 , HYPRE_MEMORY_HOST);
 
    jr = NULL;
-   lr = NULL;
+   hypre_lr = NULL;
    jw = NULL;
    w  = NULL;
 
