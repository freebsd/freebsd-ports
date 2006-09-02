
$FreeBSD$

--- examples/nettle-openssl.c.orig
+++ examples/nettle-openssl.c
@@ -35,6 +35,7 @@
 #define NCOMPAT
 #define OPENSSL_DISABLE_OLD_DES_SUPPORT
 
+#include <sys/types.h>
 #include <assert.h>
 
 #include <openssl/aes.h>
