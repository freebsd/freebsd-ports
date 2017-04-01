--- lib/storage.c.orig	2017-03-25 11:32:36 UTC
+++ lib/storage.c
@@ -15,6 +15,7 @@
  */
 
 #include <sys/types.h>
+#include <sys/endian.h>
 
 #include <stdlib.h>
 #include <stdint.h>
