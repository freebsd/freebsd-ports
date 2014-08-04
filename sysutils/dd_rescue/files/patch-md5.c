--- md5.c.orig	2014-06-29 00:53:13.000000000 +0900
+++ md5.c	2014-06-29 00:53:22.000000000 +0900
@@ -12,7 +12,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdint.h>
-#include <endian.h>
+#include <machine/endian.h>
 #include <assert.h>
 #include <netinet/in.h>
 
