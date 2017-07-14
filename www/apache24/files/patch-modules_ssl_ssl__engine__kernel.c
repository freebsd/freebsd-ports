--- modules/ssl/ssl_engine_kernel.c.orig	2017-05-02 11:01:17 UTC
+++ modules/ssl/ssl_engine_kernel.c
@@ -1733,7 +1733,7 @@ static void modssl_proxy_info_log(conn_r
  * so we need to increment here to prevent them from
  * being freed.
  */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define modssl_set_cert_info(info, cert, pkey) \
     *cert = info->x509; \
     CRYPTO_add(&(*cert)->references, +1, CRYPTO_LOCK_X509); \
