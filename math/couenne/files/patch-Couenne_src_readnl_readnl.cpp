- workaround for the 'filename' macro name clash: https://github.com/coin-or-tools/ThirdParty-ASL/issues/4

--- Couenne/src/readnl/readnl.cpp.orig	2021-05-03 20:42:36 UTC
+++ Couenne/src/readnl/readnl.cpp
@@ -10,6 +10,8 @@
 
 #include "asl.h"
 
+#undef filename
+
 // Added to avoid compiler issues with gcc 6.2.1 --- see https://github.com/JuliaOpt/CoinOptServices.jl/issues/27#issuecomment-290960312
 #undef strtod
 
@@ -60,7 +62,7 @@ void createCommonExpr (CouenneProblem *p, const ASL *a
 // Reads a MINLP from an AMPL .nl file through the ASL methods
 int CouenneProblem::readnl (const ASL *asl) {
 
-  problemName_ = filename;
+  problemName_ = asl->i.filename_; //filename;
 
   // number of defined variables (aka common expressions)
   ndefined_ = como + comc + comb + como1 + comc1; 
