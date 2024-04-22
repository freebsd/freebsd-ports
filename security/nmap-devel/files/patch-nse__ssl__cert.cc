--- nse_ssl_cert.cc.orig	2022-08-31 13:43:38 UTC
+++ nse_ssl_cert.cc
@@ -80,7 +80,9 @@
 #include <openssl/evp.h>
 #include <openssl/err.h>
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined LIBRESSL_VERSION_NUMBER
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && \
+    ((!defined LIBRESSL_VERSION_NUMBER) || \
+    (defined LIBRESSL_VERSION_NUMBER && LIBRESSL_VERSION_NUMBER >= 0x30500000L))
 /* Technically some of these things were added in 0x10100006
  * but that was pre-release. */
 #define HAVE_OPAQUE_STRUCTS 1
