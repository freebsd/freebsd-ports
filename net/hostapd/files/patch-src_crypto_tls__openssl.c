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
@@ -3105,7 +3105,8 @@ int tls_connection_get_random(void *ssl_
 #ifdef OPENSSL_NEED_EAP_FAST_PRF
 static int openssl_get_keyblock_size(SSL *ssl)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
+	(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 	const EVP_CIPHER *c;
 	const EVP_MD *h;
 	int md_size;
@@ -4159,7 +4160,8 @@ static int tls_sess_sec_cb(SSL *s, void 
 	struct tls_connection *conn = arg;
 	int ret;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
+	(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 	if (conn == NULL || conn->session_ticket_cb == NULL)
 		return 0;
 
@@ -4254,7 +4256,8 @@ int tls_connection_set_session_ticket_cb
 
 int tls_get_library_version(char *buf, size_t buf_len)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && \
+	!(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 	return os_snprintf(buf, buf_len, "OpenSSL build=%s run=%s",
 			   OPENSSL_VERSION_TEXT,
 			   OpenSSL_version(OPENSSL_VERSION));
