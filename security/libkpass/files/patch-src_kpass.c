--- src/kpass.c.orig	2011-09-12 11:39:12.476116248 +0400
+++ src/kpass.c	2011-09-12 11:39:37.962483090 +0400
@@ -19,7 +19,7 @@
 
 #include <string.h>
 #include <openssl/evp.h>
-#include <byteswap.h>
+#include <sys/endian.h>
 #include <time.h>
 
 #include "kpass.h"
