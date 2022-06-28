--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2022-06-28 10:06:55 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols_p.h
@@ -80,6 +80,13 @@ QT_BEGIN_NAMESPACE
 
 #define DUMMYARG
 
+#ifdef LIBRESSL_VERSION_NUMBER
+typedef _STACK STACK;
+typedef STACK OPENSSL_STACK;
+typedef void OPENSSL_INIT_SETTINGS;
+typedef int (*X509_STORE_CTX_verify_cb)(int ok,X509_STORE_CTX *ctx);
+#endif
+
 #if !defined QT_LINKED_OPENSSL
 // **************** Shared declarations ******************
 // ret func(arg)
@@ -496,12 +503,14 @@ int q_SSL_CTX_use_PrivateKey(SSL_CTX *a, EVP_PKEY *b);
 int q_SSL_CTX_use_RSAPrivateKey(SSL_CTX *a, RSA *b);
 int q_SSL_CTX_use_PrivateKey_file(SSL_CTX *a, const char *b, int c);
 X509_STORE *q_SSL_CTX_get_cert_store(const SSL_CTX *a);
+#ifndef LIBRESSL_VERSION_NUMBER
 SSL_CONF_CTX *q_SSL_CONF_CTX_new();
 void q_SSL_CONF_CTX_free(SSL_CONF_CTX *a);
 void q_SSL_CONF_CTX_set_ssl_ctx(SSL_CONF_CTX *a, SSL_CTX *b);
 unsigned int q_SSL_CONF_CTX_set_flags(SSL_CONF_CTX *a, unsigned int b);
 int q_SSL_CONF_CTX_finish(SSL_CONF_CTX *a);
 int q_SSL_CONF_cmd(SSL_CONF_CTX *a, const char *b, const char *c);
+#endif
 void q_SSL_free(SSL *a);
 STACK_OF(SSL_CIPHER) *q_SSL_get_ciphers(const SSL *a);
 const SSL_CIPHER *q_SSL_get_current_cipher(SSL *a);
