--- pbkdf_ossl.c.orig	2017-11-04 09:03:51 UTC
+++ pbkdf_ossl.c
@@ -11,7 +11,7 @@
 #include "md5.h"
 #include <stdlib.h>
 #include <assert.h>
-#include <endian.h>
+#include <machine/endian.h>
 #include <stdint.h>
 
 #define MIN(a,b) ((a)<(b)? (a): (b))
