--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2020-05-05 11:59:27 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -147,6 +147,14 @@ DEFINEFUNC(int, EVP_CIPHER_CTX_reset, EVP_CIPHER_CTX *
 DEFINEFUNC(int, EVP_PKEY_up_ref, EVP_PKEY *a, a, return 0, return)
 DEFINEFUNC(int, EVP_PKEY_base_id, EVP_PKEY *a, a, return NID_undef, return)
 DEFINEFUNC(int, RSA_bits, RSA *a, a, return 0, return)
+#ifdef LIBRESSL_VERSION_NUMBER
+DEFINEFUNC(int, sk_num, OPENSSL_STACK *a, a, return -1, return)
+DEFINEFUNC2(void, sk_pop_free, OPENSSL_STACK *a, a, void (*b)(void*), b, return, DUMMYARG)
+DEFINEFUNC(OPENSSL_STACK *, sk_new_null, DUMMYARG, DUMMYARG, return nullptr, return)
+DEFINEFUNC2(void, sk_push, OPENSSL_STACK *a, a, void *b, b, return, DUMMYARG)
+DEFINEFUNC(void, sk_free, OPENSSL_STACK *a, a, return, DUMMYARG)
+DEFINEFUNC2(void *, sk_value, OPENSSL_STACK *a, a, int b, b, return nullptr, return)
+#else
 DEFINEFUNC(int, DSA_bits, DSA *a, a, return 0, return)
 DEFINEFUNC(int, OPENSSL_sk_num, OPENSSL_STACK *a, a, return -1, return)
 DEFINEFUNC2(void, OPENSSL_sk_pop_free, OPENSSL_STACK *a, a, void (*b)(void*), b, return, DUMMYARG)
@@ -154,6 +162,7 @@ DEFINEFUNC(OPENSSL_STACK *, OPENSSL_sk_new_null, DUMMY
 DEFINEFUNC2(void, OPENSSL_sk_push, OPENSSL_STACK *a, a, void *b, b, return, DUMMYARG)
 DEFINEFUNC(void, OPENSSL_sk_free, OPENSSL_STACK *a, a, return, DUMMYARG)
 DEFINEFUNC2(void *, OPENSSL_sk_value, OPENSSL_STACK *a, a, int b, b, return nullptr, return)
+#endif
 DEFINEFUNC(int, SSL_session_reused, SSL *a, a, return 0, return)
 DEFINEFUNC2(unsigned long, SSL_CTX_set_options, SSL_CTX *ctx, ctx, unsigned long op, op, return 0, return)
 #ifdef TLS1_3_VERSION
@@ -351,12 +360,14 @@ DEFINEFUNC2(int, SSL_CTX_use_PrivateKey, SSL_CTX *a, a
 DEFINEFUNC2(int, SSL_CTX_use_RSAPrivateKey, SSL_CTX *a, a, RSA *b, b, return -1, return)
 DEFINEFUNC3(int, SSL_CTX_use_PrivateKey_file, SSL_CTX *a, a, const char *b, b, int c, c, return -1, return)
 DEFINEFUNC(X509_STORE *, SSL_CTX_get_cert_store, const SSL_CTX *a, a, return nullptr, return)
+#if !defined(LIBRESSL_VERSION_NUMBER)
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
@@ -834,12 +845,21 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(EVP_PKEY_up_ref)
     RESOLVEFUNC(EVP_PKEY_base_id)
     RESOLVEFUNC(RSA_bits)
+#ifdef LIBRESSL_VERSION_NUMBER
+    RESOLVEFUNC(sk_new_null)
+    RESOLVEFUNC(sk_push)
+    RESOLVEFUNC(sk_free)
+    RESOLVEFUNC(sk_num)
+    RESOLVEFUNC(sk_pop_free)
+    RESOLVEFUNC(sk_value)
+#else
     RESOLVEFUNC(OPENSSL_sk_new_null)
     RESOLVEFUNC(OPENSSL_sk_push)
     RESOLVEFUNC(OPENSSL_sk_free)
     RESOLVEFUNC(OPENSSL_sk_num)
     RESOLVEFUNC(OPENSSL_sk_pop_free)
     RESOLVEFUNC(OPENSSL_sk_value)
+#endif
     RESOLVEFUNC(DH_get0_pqg)
     RESOLVEFUNC(SSL_CTX_set_options)
 
@@ -881,7 +901,9 @@ bool q_resolveOpenSslSymbols()
 
     RESOLVEFUNC(SSL_SESSION_get_ticket_lifetime_hint)
     RESOLVEFUNC(DH_bits)
+#ifndef LIBRESSL_VERSION_NUMBER
     RESOLVEFUNC(DSA_bits)
+#endif
 
 #if QT_CONFIG(dtls)
     RESOLVEFUNC(DTLSv1_listen)
@@ -1041,12 +1063,14 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(SSL_CTX_use_RSAPrivateKey)
     RESOLVEFUNC(SSL_CTX_use_PrivateKey_file)
     RESOLVEFUNC(SSL_CTX_get_cert_store);
+#if !defined(LIBRESSL_VERSION_NUMBER)
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
