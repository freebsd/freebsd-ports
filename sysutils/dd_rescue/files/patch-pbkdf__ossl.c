--- pbkdf_ossl.c.orig	2021-04-14 08:23:02 UTC
+++ pbkdf_ossl.c
@@ -12,7 +12,7 @@
 #include "secmem.h"
 #include <stdlib.h>
 #include <assert.h>
-#include <endian.h>
+#include <machine/endian.h>
 #include <stdint.h>
 
 #define MIN(a,b) ((a)<(b)? (a): (b))
