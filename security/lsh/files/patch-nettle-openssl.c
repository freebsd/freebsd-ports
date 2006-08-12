--- src/nettle/examples/nettle-openssl.c.orig	Thu Aug 10 13:24:43 2006
+++ src/nettle/examples/nettle-openssl.c	Thu Aug 10 13:24:53 2006
@@ -36,6 +36,7 @@
 #define OPENSSL_DISABLE_OLD_DES_SUPPORT
 
 #include <assert.h>
+#include <stddef.h>
 
 #include <openssl/aes.h>
 #include <openssl/blowfish.h>
