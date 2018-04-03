--- src/ssl_compat.h.orig	2018-02-27 12:18:50 UTC
+++ src/ssl_compat.h
@@ -26,16 +26,22 @@
 
 #include <openssl/opensslv.h>
 
-#if defined(LIBRESSL_VERSION_NUMBER)
-#define LIBRESSL_IN_USE 1
-#else // !defined(LIBRESSL_VERSION_NUMBER)
-#define LIBRESSL_IN_USE 0
-#endif // !defined(LIBRESSL_VERSION_NUMBER)
+#if defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L
+#define LIBRESSL_1_0_API 1
+#define LIBRESSL_1_1_API 0
+#elif defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x20700000L
+#define LIBRESSL_1_0_API 0
+#define LIBRESSL_1_1_API 1
+#else // !defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L
+#define LIBRESSL_1_0_API 0
+#define LIBRESSL_1_1_API 0
+#endif // !defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L
 
 #define OPENSSL_1_1_API                                                        \
-  (!LIBRESSL_IN_USE && OPENSSL_VERSION_NUMBER >= 0x1010000fL)
+  (!LIBRESSL_1_0_API && OPENSSL_VERSION_NUMBER >= 0x1010000fL)
 
 #define OPENSSL_1_1_1_API                                                      \
-  (!LIBRESSL_IN_USE && OPENSSL_VERSION_NUMBER >= 0x10101000L)
+  (!LIBRESSL_1_0_API && !LIBRESSL_1_1_API &&                                   \
+   OPENSSL_VERSION_NUMBER >= 0x10101000L)
 
 #endif // OPENSSL_COMPAT_H
