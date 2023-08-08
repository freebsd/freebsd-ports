--- 0d1n_viewer/lib/krypton/src/ktypes.h.orig	2023-02-20 12:36:40 UTC
+++ 0d1n_viewer/lib/krypton/src/ktypes.h
@@ -18,11 +18,6 @@
 #define NS_INTERNAL
 #endif
 
-/* C99 and later requires alloca.h. */
-#if defined(__STDC_VERSION__) && __STDC_VERSION__ > 199900L
-#include <alloca.h>
-#endif
-
 #include <assert.h>
 #include <ctype.h>
 #include <errno.h>
