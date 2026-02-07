--- math_mpfr_include.h.orig	2024-11-13 04:28:47 UTC
+++ math_mpfr_include.h
@@ -178,7 +178,6 @@ FALLBACK_NOTIFY          : If defined, $Math::MPFR::do
 #include <float.h>
 
 #if defined(MPFR_WANT_FLOAT128) || defined(USE_QUADMATH)
-#include <quadmath.h>
 #if defined(USE_QUADMATH) && defined(MPFR_WANT_FLOAT128) && defined(MPFR_VERSION) && MPFR_VERSION >= MPFR_VERSION_NUM(4,0,0)
 #define CAN_PASS_FLOAT128
 #endif
