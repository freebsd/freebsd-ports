--- common/ssl_calls.c.orig	2016-12-22 17:04:29 UTC
+++ common/ssl_calls.c
@@ -40,7 +40,7 @@
 #define OLD_RSA_GEN1
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 static inline HMAC_CTX *
 HMAC_CTX_new()
 {
