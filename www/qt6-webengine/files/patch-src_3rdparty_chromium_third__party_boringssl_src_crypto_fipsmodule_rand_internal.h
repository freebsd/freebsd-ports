--- src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/rand/internal.h.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/rand/internal.h
@@ -27,7 +27,8 @@ extern "C" {
 
 
 #if !defined(OPENSSL_WINDOWS) && !defined(OPENSSL_FUCHSIA) && \
-    !defined(BORINGSSL_UNSAFE_DETERMINISTIC_MODE) && !defined(OPENSSL_TRUSTY)
+    !defined(BORINGSSL_UNSAFE_DETERMINISTIC_MODE) && !defined(OPENSSL_TRUSTY) && \
+    !defined(OPENSSL_ARC4RANDOM)
 #define OPENSSL_URANDOM
 #endif
 
