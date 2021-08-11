- workaround for https://github.com/siconos/siconos/issues/410

--- numerics/src/tools/GAMSlink.c.orig	2021-08-11 22:15:55 UTC
+++ numerics/src/tools/GAMSlink.c
@@ -1,5 +1,6 @@
 /* GAMS stuff */
 
+#if 0
 #define _XOPEN_SOURCE 700
 
 #if (__linux ||  __APPLE__)
@@ -14,6 +15,7 @@ static inline char* strdup(const char* src)
   return dest;
 }
 #endif
+#endif
 #include "SiconosConfig.h" // for HAVE_GAMS_C_API
 #include <math.h>
 #ifdef HAVE_GAMS_C_API
