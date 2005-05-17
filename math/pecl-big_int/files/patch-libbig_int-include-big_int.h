--- libbig_int/include/big_int.h.orig	Wed May 11 16:11:09 2005
+++ libbig_int/include/big_int.h	Tue May 17 21:01:26 2005
@@ -77,9 +77,9 @@
 #endif /* end of BIG_INT_DIGIT_SIZE */
 #else
 /*
-    for ANSI C99 compliant comilers, which have stdint.h header
+    for ANSI C99 compliant compilers, which have inttypes.h header
 */
-#include <stdint.h>
+#include <inttypes.h>
 #if (BIG_INT_DIGIT_SIZE == 32)
 typedef uint32_t big_int_word;
 typedef uint64_t big_int_dword;
