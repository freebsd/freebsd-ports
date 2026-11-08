--- src/3rdparty/chromium/third_party/boringssl/src/include/openssl/target.h.orig	2026-05-08 07:54:08 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/include/openssl/target.h
@@ -54,6 +54,9 @@
 #define OPENSSL_32_BIT
 #elif defined(__myriad2__)
 #define OPENSSL_32_BIT
+#elif defined(__powerpc64__)
+#define OPENSSL_64_BIT
+#define OPENSSL_PPC64
 #else
 // The list above enumerates the platforms that BoringSSL supports. For these
 // platforms we keep a reasonable bar of not breaking them: automated test
