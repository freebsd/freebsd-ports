--- third_party/boringssl/src/include/openssl/base.h.orig	2022-07-22 17:30:31 UTC
+++ third_party/boringssl/src/include/openssl/base.h
@@ -155,6 +155,11 @@ extern "C" {
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
