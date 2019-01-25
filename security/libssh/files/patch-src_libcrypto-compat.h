--- src/libcrypto-compat.h	2018-10-19 05:11:14 UTC
+++ src/libcrypto-compat.h
@@ -2,7 +2,8 @@
 #define LIBCRYPTO_COMPAT_H
 
 #include <openssl/opensslv.h>
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
+    (defined(LIBRESSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x20700000L)
 
 #include <openssl/rsa.h>
 #include <openssl/dsa.h>
