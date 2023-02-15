--- lib/Solver/Z3Solver.cpp.orig	2022-04-04 12:37:59 UTC
+++ lib/Solver/Z3Solver.cpp
@@ -362,7 +362,7 @@ SolverImpl::SolverRunStatus Z3SolverImpl::handleSolver
         __attribute__((unused))
         bool successfulEval =
             Z3_model_eval(builder->ctx, theModel, initial_read,
-                          /*model_completion=*/Z3_TRUE, &arrayElementExpr);
+                          /*model_completion=*/true, &arrayElementExpr);
         assert(successfulEval && "Failed to evaluate model");
         Z3_inc_ref(builder->ctx, arrayElementExpr);
         assert(Z3_get_ast_kind(builder->ctx, arrayElementExpr) ==
@@ -432,7 +432,7 @@ bool Z3SolverImpl::validateZ3Model(::Z3_solver &theSol
     __attribute__((unused))
     bool successfulEval =
         Z3_model_eval(builder->ctx, theModel, constraint,
-                      /*model_completion=*/Z3_TRUE, &rawEvaluatedExpr);
+                      /*model_completion=*/true, &rawEvaluatedExpr);
     assert(successfulEval && "Failed to evaluate model");
 
     // Use handle to do ref-counting.
