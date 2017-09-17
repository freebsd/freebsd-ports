--- pki.c.orig	2017-01-03 21:41:42 UTC
+++ pki.c
@@ -10,6 +10,7 @@
 #include <limits.h>
 #include <openssl/pem.h>
 #include <openssl/err.h>
+#include <openssl/opensslv.h>
 #include <fcntl.h>
 #include "config.h"
 #include <libisns/isns.h>
@@ -30,7 +31,7 @@ static int	i2d_DSA_PUBKEY_backwards(DSA 
 #endif
 /* OpenSSL 1.1 made a lot of structures opaque, so we need to
  * define the 1.1 wrappers in previous versions. */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define EVP_PKEY_base_id(o)  ((o)->type)
 #define EVP_PKEY_get0_DSA(o) ((o)->pkey.dsa)
 static EVP_MD_CTX *EVP_MD_CTX_new(void)
