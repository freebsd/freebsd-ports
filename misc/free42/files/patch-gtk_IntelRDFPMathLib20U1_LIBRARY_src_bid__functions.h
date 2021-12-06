--- gtk/IntelRDFPMathLib20U1/LIBRARY/src/bid_functions.h.orig	2021-12-06 09:51:34 UTC
+++ gtk/IntelRDFPMathLib20U1/LIBRARY/src/bid_functions.h
@@ -36,17 +36,9 @@
 #ifndef _BID_FUNCTIONS_H
 #define _BID_FUNCTIONS_H
 
-#if !defined (__GNUC__) || defined(__QNX__)
 #include <wchar.h>
-#endif
 #include <ctype.h>
 
-// Fix system header issue on Sun solaris and define required type by ourselves
-#if !defined(_WCHAR_T) && !defined(_WCHAR_T_DEFINED) && !defined(__QNX__)
-typedef int   wchar_t;
-#endif
-
-
 #ifdef IN_LIBGCC2
 // When we are built as the part of the gcc runtime library, libgcc,
 // we will use gcc types defined in bid_gcc_intrinsics.h.
@@ -159,11 +151,7 @@ typedef unsigned    long fexcept_t;
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
 
