--- Cbc/src/CbcModel.cpp.orig	2019-12-21 21:30:53 UTC
+++ Cbc/src/CbcModel.cpp
@@ -5417,7 +5417,7 @@ void CbcModel::branchAndBound(int doStatistics)
     OsiClpSolverInterface *clpSolver
       = dynamic_cast< OsiClpSolverInterface * >(solver_);
     if (clpSolver)
-      clpSolver->setFakeObjective(reinterpret_cast< double * >(NULL));
+      clpSolver->setFakeObjective((double*)nullptr);
   }
 #endif
   moreSpecialOptions_ = saveMoreSpecialOptions;
