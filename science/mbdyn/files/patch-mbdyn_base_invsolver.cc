--- mbdyn/base/invsolver.cc.orig	2017-09-09 09:20:12 UTC
+++ mbdyn/base/invsolver.cc
@@ -76,6 +76,8 @@
 
 #include "solver_impl.h"
 
+extern "C" {int get_nprocs(void);}
+
 InverseSolver::InverseSolver(MBDynParser& HPar,
 		const std::string& sInFName,
 		const std::string& sOutFName,
