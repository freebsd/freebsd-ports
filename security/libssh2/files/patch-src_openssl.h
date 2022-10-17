--- src/openssl.h.orig	2022-10-17 08:18:24 UTC
+++ src/openssl.h
@@ -57,8 +57,7 @@
 #include <openssl/pem.h>
 #include <openssl/rand.h>
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && \
-    !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 # define HAVE_OPAQUE_STRUCTS 1
 #endif
 
