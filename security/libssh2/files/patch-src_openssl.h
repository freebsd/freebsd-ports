Backported from upstream commit
<https://github.com/libssh2/libssh2/commit/b952674f>

--- src/openssl.h.orig	2021-05-14 21:36:06 UTC
+++ src/openssl.h
@@ -57,8 +57,9 @@
 #include <openssl/pem.h>
 #include <openssl/rand.h>
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && \
-    !defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && \
+    !defined(LIBRESSL_VERSION_NUMBER)) || \
+    LIBRESSL_VERSION_NUMBER >= 0x3050000fL
 # define HAVE_OPAQUE_STRUCTS 1
 #endif
 
