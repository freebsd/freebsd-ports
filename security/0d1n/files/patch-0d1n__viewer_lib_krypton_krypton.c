--- 0d1n_viewer/lib/krypton/krypton.c.orig	2023-02-20 12:36:21 UTC
+++ 0d1n_viewer/lib/krypton/krypton.c
@@ -112,11 +112,6 @@ typedef struct {
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
