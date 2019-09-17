--- src/util/io.c.orig	2019-08-21 19:15:04 UTC
+++ src/util/io.c
@@ -8,6 +8,7 @@
 #endif
 
 #include <errno.h>
+#include <fcntl.h>
 #include <inttypes.h>
 #include <limits.h>
 #include <string.h>
