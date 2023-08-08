--- image-hd.c.orig	2023-01-06 17:53:09 UTC
+++ image-hd.c
@@ -22,7 +22,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <inttypes.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include <stdbool.h>
 #include <unistd.h>
 #include <sys/types.h>
