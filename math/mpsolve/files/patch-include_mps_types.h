- workaround for https://github.com/robol/MPSolve/issues/38

--- include/mps/types.h.orig	2023-11-09 17:34:55 UTC
+++ include/mps/types.h
@@ -22,6 +22,7 @@ typedef int mps_debug_level;
 
 /* Handle systems where isnan and isinf are not available */
 #include <math.h>
+#if 0
 #ifndef isnan
           # define isnan(x) \
   (sizeof(x) == sizeof(long double) ? isnan_ld (x) \
@@ -58,6 +59,7 @@ static inline int isinf_ld (long double x)
 {
   return !isnan (x) && isnan (x - x);
 }
+#endif
 #endif
 
 #include <mps/mt-types.h>
