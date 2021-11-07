--- distributed_ls/pilut/DistributedMatrixPilutSolver.h.orig	2021-11-07 01:57:53 UTC
+++ distributed_ls/pilut/DistributedMatrixPilutSolver.h
@@ -86,7 +86,7 @@ HYPRE_Int Ul_timer;
 #define jr (globals->_jr)
 #define jw (globals->_jw)
 #define lastjr (globals->_lastjr)
-#define lr (globals->_lr)
+#define hypre_lr (globals->_lr)
 #define lastlr (globals->_lastlr)
 #define w (globals->_w)
 #define firstrow (globals->_firstrow)
