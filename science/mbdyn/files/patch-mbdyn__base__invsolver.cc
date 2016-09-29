--- mbdyn/base/invsolver.cc.orig	2016-04-24 19:10:43 UTC
+++ mbdyn/base/invsolver.cc
@@ -114,8 +114,8 @@ InverseSolver::Prepare(void)
 		pRTSolver->Setup();
 	}
 
-#ifdef USE_SCHUR
 	int mpi_finalize = 0;
+#ifdef USE_SCHUR
 
 	if (bParallel) {
 		DEBUGLCOUT(MYDEBUG_MEM, "creating parallel SchurDataManager"
