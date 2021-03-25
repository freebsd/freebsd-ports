--- gtk/IntelRDFPMathLib20U1/LIBRARY/src/bid_functions.h.orig	2021-03-25 17:43:14 UTC
+++ gtk/IntelRDFPMathLib20U1/LIBRARY/src/bid_functions.h
@@ -159,11 +159,7 @@ typedef unsigned    long fexcept_t;
 typedef unsigned bid__int64 fexcept_t;
 #endif
 #else
-#ifdef __QNX__
 #include <fenv.h>
-#else
-typedef unsigned short int fexcept_t;
-#endif
 #endif
 #endif
 
