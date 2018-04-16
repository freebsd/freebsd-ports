--- Cbc/src/CbcModel.cpp.orig	2018-04-16 07:45:54 UTC
+++ Cbc/src/CbcModel.cpp
@@ -5338,7 +5338,7 @@ void CbcModel::branchAndBound(int doStat
         OsiClpSolverInterface * clpSolver
         = dynamic_cast<OsiClpSolverInterface *> (solver_);
         if (clpSolver)
-            clpSolver->setFakeObjective(reinterpret_cast<double *> (NULL));
+            clpSolver->setFakeObjective((double*)nullptr);
     }
 #endif
     moreSpecialOptions_ = saveMoreSpecialOptions;
