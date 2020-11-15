--- bin/interop-decode.c.orig	2020-05-28 18:23:09 UTC
+++ bin/interop-decode.c
@@ -41,7 +41,7 @@
 
 #include "lsqpack.h"
 #include "lsxpack_header.h"
-#include "xxhash.h"
+#include <xxhash.h>
 #ifndef DEBUG
 #include "lsqpack-test.h"
 #endif
