--- md4.c.orig	2011-05-16 18:18:54.288522284 +0200
+++ md4.c	2011-05-16 18:19:21.930002696 +0200
@@ -25,6 +25,8 @@
    It assumes that a int is at least 32 bits long
 */
 
+#include <string.h>
+
 typedef unsigned int uint32;
 
 static uint32 A, B, C, D;
