--- modules/ssl/ssl_util.c.orig	2017-03-24 13:31:03 UTC
+++ modules/ssl/ssl_util.c
@@ -247,7 +247,7 @@ void ssl_asn1_table_unset(apr_hash_t *ta
 }
 
 #if APR_HAS_THREADS
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /*
  * To ensure thread-safetyness in OpenSSL - work in progress
  */
