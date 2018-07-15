--- find_nonzero_sse2.c.orig	2016-12-28 21:17:50 UTC
+++ find_nonzero_sse2.c
@@ -5,6 +5,7 @@
  */
 
 #include "find_nonzero.h"
+#include "ffs.h"
 
 #if defined(__SSE2__)
 #include <emmintrin.h>
