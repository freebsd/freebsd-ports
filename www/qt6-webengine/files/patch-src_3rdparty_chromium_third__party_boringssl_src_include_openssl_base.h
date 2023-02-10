--- src/3rdparty/chromium/third_party/boringssl/src/include/openssl/base.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/include/openssl/base.h
@@ -153,6 +153,11 @@ extern "C" {
 #define OPENSSL_FUCHSIA
 #endif
 
+#if defined(__OpenBSD__)
+#define OPENSSL_OPENBSD
+#define OPENSSL_ARC4RANDOM
+#endif   
+
 #if defined(__TRUSTY__)
 #define OPENSSL_TRUSTY
 #define OPENSSL_NO_THREADS_CORRUPT_MEMORY_AND_LEAK_SECRETS_IF_THREADED
