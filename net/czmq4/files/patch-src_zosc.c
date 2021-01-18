--- src/zosc.c.orig	2021-01-18 10:20:29 UTC
+++ src/zosc.c
@@ -23,7 +23,7 @@
 #endif
 #include "czmq_classes.h"
 #if __unix__ && !__APPLE__
-#include <endian.h>
+#include <sys/endian.h>
 #define htonll(x) htobe64(x)
 #define ntohll(x) be64toh(x)
 #endif
