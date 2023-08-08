--- libssh2/src/openssl.h.orig	2022-06-29 20:40:29 UTC
+++ libssh2/src/openssl.h
@@ -57,8 +57,9 @@
 #include <openssl/pem.h>
 #include <openssl/rand.h>
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && \
-    !defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && \
+    ((!defined LIBRESSL_VERSION_NUMBER) || \
+    (defined LIBRESSL_VERSION_NUMBER && LIBRESSL_VERSION_NUMBER >= 0x30500000L))
 # define HAVE_OPAQUE_STRUCTS 1
 #endif
 
