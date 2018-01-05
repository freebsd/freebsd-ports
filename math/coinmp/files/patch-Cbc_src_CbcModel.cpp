CbcModel.cpp:5322:41: error: reinterpret_cast from 'nullptr_t' to 'double *' is not allowed
            clpSolver->setFakeObjective(reinterpret_cast<double *> (NULL));
                                        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- Cbc/src/CbcModel.cpp.orig	2015-06-04 17:10:17 UTC
+++ Cbc/src/CbcModel.cpp
@@ -5319,7 +5319,7 @@ void CbcModel::branchAndBound(int doStatistics)
         OsiClpSolverInterface * clpSolver
         = dynamic_cast<OsiClpSolverInterface *> (solver_);
         if (clpSolver)
-            clpSolver->setFakeObjective(reinterpret_cast<double *> (NULL));
+            clpSolver->setFakeObjective(static_cast<double *> (NULL));
     }
 #endif
     moreSpecialOptions_ = saveMoreSpecialOptions;
