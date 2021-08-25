# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=258030
# Based on https://github.com/DomBlack/php-scrypt/pull/56
--- crypto/crypto_scrypt-nosse.c.orig	2016-05-18 14:49:13 UTC
+++ crypto/crypto_scrypt-nosse.c
@@ -45,6 +45,7 @@
 #include "sysendian.h"
 
 #include "crypto_scrypt.h"
+#include "php_scrypt.h"
 
 static void blkcpy(uint8_t *, uint8_t *, size_t);
 static void blkxor(uint8_t *, uint8_t *, size_t);
