--- ./mbdyn/base/invsolver.cc.orig	2009-04-10 13:25:00.000000000 +0200
+++ ./mbdyn/base/invsolver.cc	2010-10-31 23:14:49.000000000 +0100
@@ -200,8 +200,8 @@
 		}
 	}
 
-#ifdef USE_SCHUR
 	int mpi_finalize = 0;
+#ifdef USE_SCHUR
 
 	int MyRank = 0;
 	if (bParallel) {
