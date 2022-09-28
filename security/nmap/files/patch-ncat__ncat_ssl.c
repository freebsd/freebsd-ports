--- ncat/ncat_ssl.c.orig	2022-08-29 17:09:47 UTC
+++ ncat/ncat_ssl.c
@@ -73,7 +73,9 @@
 #include <openssl/x509.h>
 #include <openssl/x509v3.h>
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined LIBRESSL_VERSION_NUMBER
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && \
+    ((!defined LIBRESSL_VERSION_NUMBER) || \
+    (defined LIBRESSL_VERSION_NUMBER && LIBRESSL_VERSION_NUMBER >= 0x30500000L))
 #define HAVE_OPAQUE_STRUCTS 1
 #define FUNC_ASN1_STRING_data ASN1_STRING_get0_data
 #else
