- workaround for errors like:
- ld: error: undefined reference due to --no-allow-shlib-undefined: __progname
- >>> referenced by /lib/libc.so.7

--- demos/ErrorEstimation/CustomModel/CustomModel.cpp.orig	2023-07-19 16:59:14 UTC
+++ demos/ErrorEstimation/CustomModel/CustomModel.cpp
@@ -2,6 +2,9 @@
 
 #include "CustomModel.h"
 
+char **environ = nullptr;
+const char *__progname = "x";
+
 // Here we use the BuildOp function provided by clad to build a multiplication
 // expression that clad can generate code for.
 clang::Expr* CustomModel::AssignError(clad::StmtDiff refExpr,
