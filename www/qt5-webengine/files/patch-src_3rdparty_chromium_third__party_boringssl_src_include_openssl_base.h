--- src/3rdparty/chromium/third_party/boringssl/src/include/openssl/base.h.orig	2019-05-23 14:39:34.000000000 +0200
+++ src/3rdparty/chromium/third_party/boringssl/src/include/openssl/base.h	2019-10-29 11:49:25.706601000 +0100
@@ -96,9 +96,13 @@
 #elif defined(__arm) || defined(__arm__) || defined(_M_ARM)
 #define OPENSSL_32_BIT
 #define OPENSSL_ARM
-#elif (defined(__PPC64__) || defined(__powerpc64__)) && defined(_LITTLE_ENDIAN)
+#elif (defined(__PPC64__) || defined(__powerpc64__)) && defined(__LITTLE_ENDIAN__)
 #define OPENSSL_64_BIT
 #define OPENSSL_PPC64LE
+#elif (defined(__PPC64__) || defined(__powerpc64__))
+#define OPENSSL_64_BIT
+#define OPENSSL_PPC64
+#define OPENSSL_BIGENDIAN
 #elif defined(__mips__) && !defined(__LP64__)
 #define OPENSSL_32_BIT
 #define OPENSSL_MIPS
