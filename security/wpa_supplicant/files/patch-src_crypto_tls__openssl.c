--- src/crypto/tls_openssl.c.orig	2016-10-02 18:51:11 UTC
+++ src/crypto/tls_openssl.c
@@ -59,7 +59,7 @@ typedef int stack_index_t;
 #endif /* SSL_set_tlsext_status_type */
 
 #if (OPENSSL_VERSION_NUMBER < 0x10100000L || \
-     defined(LIBRESSL_VERSION_NUMBER)) &&    \
+     (defined(LIBRESSL_VERSION_NUMBER)) && LIBRESSL_VERSION_NUMBER < 0x20700000L) && \
     !defined(BORINGSSL_API_VERSION)
 /*
  * SSL_get_client_random() and SSL_get_server_random() were added in OpenSSL
@@ -919,7 +919,7 @@ void * tls_init(const struct tls_config 
 		}
 #endif /* OPENSSL_FIPS */
 #endif /* CONFIG_FIPS */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 		SSL_load_error_strings();
 		SSL_library_init();
 #ifndef OPENSSL_NO_SHA256
@@ -1043,7 +1043,7 @@ void tls_deinit(void *ssl_ctx)
 
 	tls_openssl_ref_count--;
 	if (tls_openssl_ref_count == 0) {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #ifndef OPENSSL_NO_ENGINE
 		ENGINE_cleanup();
 #endif /* OPENSSL_NO_ENGINE */
@@ -3976,7 +3976,7 @@ int tls_connection_set_params(void *tls_
 		engine_id = "pkcs11";
 
 #if defined(EAP_FAST) || defined(EAP_FAST_DYNAMIC) || defined(EAP_SERVER_FAST)
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 	if (params->flags & TLS_CONN_EAP_FAST) {
 		wpa_printf(MSG_DEBUG,
 			   "OpenSSL: Use TLSv1_method() for EAP-FAST");
