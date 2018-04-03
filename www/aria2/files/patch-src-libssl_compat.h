--- src/libssl_compat.h.orig	2017-11-08 12:43:40 UTC
+++ src/libssl_compat.h
@@ -37,7 +37,7 @@
 
 #include <openssl/opensslv.h>
 
-#if defined(LIBRESSL_VERSION_NUMBER)
+#if (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x20700000fL)
 #define LIBRESSL_IN_USE 1
 #else // !defined(LIBRESSL_VERSION_NUMBER)
 #define LIBRESSL_IN_USE 0
