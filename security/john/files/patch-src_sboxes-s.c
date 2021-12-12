--- src/sboxes-s.c.orig	2021-12-13 00:08:30.419393000 +0100
+++ src/sboxes-s.c	2021-12-13 00:08:41.847880000 +0100
@@ -32,6 +32,7 @@
 #define regs 8
 #else
 /* PowerPC with AltiVec, etc. */
+#include <altivec.h>
 #define regs 32
 #endif
 
