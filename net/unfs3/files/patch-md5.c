--- md5.c.orig	2022-11-17 12:35:16 UTC
+++ md5.c
@@ -54,6 +54,7 @@
 
 #include "md5.h"
 #include <string.h>
+#include <stdint.h>
 
 #undef BYTE_ORDER		       /* 1 = big-endian, -1 = little-endian, 
 				          0 = unknown */
@@ -162,7 +163,7 @@ static void md5_process(md5_state_t * pms, const md5_b
 	     * On little-endian machines, we can process properly aligned
 	     * data without copying it.
 	     */
-	    if (!((data - (const md5_byte_t *) 0) & 3)) {
+	    if (((uintptr_t)data & 3) == 0) {
 		/* data are properly aligned */
 		X = (const md5_word_t *) data;
 	    } else {
