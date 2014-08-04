--- find_nonzero_sse2.c.orig	2014-06-29 01:06:51.000000000 +0900
+++ find_nonzero_sse2.c	2014-06-29 01:07:11.000000000 +0900
@@ -5,6 +5,7 @@
  */
 
 #include "find_nonzero.h"
+#include "ffs.h"
 
 #if defined(__SSE2__)
 #include <emmintrin.h>
