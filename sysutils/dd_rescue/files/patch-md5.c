--- md5.c.orig	2017-11-04 09:03:51 UTC
+++ md5.c
@@ -12,7 +12,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdint.h>
-#include <endian.h>
+#include <machine/endian.h>
 #include <assert.h>
 #include <netinet/in.h>
 
