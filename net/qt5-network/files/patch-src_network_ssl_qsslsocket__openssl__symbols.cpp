--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2022-06-28 10:13:07 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -355,12 +355,14 @@ DEFINEFUNC2(int, SSL_CTX_use_PrivateKey, SSL_CTX *a, a
 DEFINEFUNC2(int, SSL_CTX_use_RSAPrivateKey, SSL_CTX *a, a, RSA *b, b, return -1, return)
 DEFINEFUNC3(int, SSL_CTX_use_PrivateKey_file, SSL_CTX *a, a, const char *b, b, int c, c, return -1, return)
 DEFINEFUNC(X509_STORE *, SSL_CTX_get_cert_store, const SSL_CTX *a, a, return nullptr, return)
+#ifndef LIBRESSL_VERSION_NUMBER
 DEFINEFUNC(SSL_CONF_CTX *, SSL_CONF_CTX_new, DUMMYARG, DUMMYARG, return nullptr, return);
 DEFINEFUNC(void, SSL_CONF_CTX_free, SSL_CONF_CTX *a, a, return ,return);
 DEFINEFUNC2(void, SSL_CONF_CTX_set_ssl_ctx, SSL_CONF_CTX *a, a, SSL_CTX *b, b, return, return);
 DEFINEFUNC2(unsigned int, SSL_CONF_CTX_set_flags, SSL_CONF_CTX *a, a, unsigned int b, b, return 0, return);
 DEFINEFUNC(int, SSL_CONF_CTX_finish, SSL_CONF_CTX *a, a, return 0, return);
 DEFINEFUNC3(int, SSL_CONF_cmd, SSL_CONF_CTX *a, a, const char *b, b, const char *c, c, return 0, return);
+#endif
 DEFINEFUNC(void, SSL_free, SSL *a, a, return, DUMMYARG)
 DEFINEFUNC(STACK_OF(SSL_CIPHER) *, SSL_get_ciphers, const SSL *a, a, return nullptr, return)
 DEFINEFUNC(const SSL_CIPHER *, SSL_get_current_cipher, SSL *a, a, return nullptr, return)
@@ -1066,12 +1068,14 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(SSL_CTX_use_RSAPrivateKey)
     RESOLVEFUNC(SSL_CTX_use_PrivateKey_file)
     RESOLVEFUNC(SSL_CTX_get_cert_store);
+#ifndef LIBRESSL_VERSION_NUMBER
     RESOLVEFUNC(SSL_CONF_CTX_new);
     RESOLVEFUNC(SSL_CONF_CTX_free);
     RESOLVEFUNC(SSL_CONF_CTX_set_ssl_ctx);
     RESOLVEFUNC(SSL_CONF_CTX_set_flags);
     RESOLVEFUNC(SSL_CONF_CTX_finish);
     RESOLVEFUNC(SSL_CONF_cmd);
+#endif
     RESOLVEFUNC(SSL_accept)
     RESOLVEFUNC(SSL_clear)
     RESOLVEFUNC(SSL_connect)
