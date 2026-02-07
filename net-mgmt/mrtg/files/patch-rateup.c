--- src/rateup.c.orig	2022-01-19 10:25:16 UTC
+++ src/rateup.c
@@ -49,11 +49,6 @@
 #define GFORM_GD gdImagePng
 #endif
 
-/* BSD* does not have/need malloc.h */
-#if !defined(bsdi) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__APPLE__)
-#include <malloc.h>
-#endif
-
 /* MSVCRT.DLL does not know %ll in printf */
 #ifdef __MINGW32_VERSION
 #define LLD "%I64d"
