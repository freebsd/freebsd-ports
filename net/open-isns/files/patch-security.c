--- security.c.orig	2017-01-03 21:41:42 UTC
+++ security.c
@@ -15,7 +15,7 @@
 
 #ifdef WITH_SECURITY
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define EVP_PKEY_base_id(o) ((o)->type)
 #endif
 
