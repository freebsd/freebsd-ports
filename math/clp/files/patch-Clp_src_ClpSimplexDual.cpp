--- Clp/src/ClpSimplexDual.cpp.orig	2019-12-29 17:45:58 UTC
+++ Clp/src/ClpSimplexDual.cpp
@@ -3559,7 +3559,7 @@ void moveAndZero(clpTempInfo *info, int type, void *ex
 #elif defined(__arm__)
 #include <arm_neon.h>
 #else
-#include <immintrin.h>
+//#include <immintrin.h>
 //#include <fmaintrin.h>
 #endif
 int ClpSimplexDual::dualColumn0(const CoinIndexedVector *rowArray,
