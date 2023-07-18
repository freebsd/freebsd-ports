- workaround for errors like:
- ld: error: undefined reference due to --no-allow-shlib-undefined: __progname
- >>> referenced by /lib/libc.so.7

--- demos/ErrorEstimation/PrintModel/PrintModel.cpp.orig	2023-07-18 14:54:11 UTC
+++ demos/ErrorEstimation/PrintModel/PrintModel.cpp
@@ -4,6 +4,9 @@
 #include "PrintModel.h"
 #include "clad/Differentiator/CladUtils.h"
 
+char **environ = nullptr;
+const char *__progname = "x";
+
 // Here we use the BuildOp function provided by clad to build a multiplication
 // expression that clad can generate code for.
 clang::Expr* PrintModel::AssignError(clad::StmtDiff refExpr,
