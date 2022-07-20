--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2022-07-05 09:21:21 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -142,13 +142,18 @@ DEFINEFUNC2(int, OPENSSL_init_ssl, uint64_t opts, opts
 DEFINEFUNC2(int, OPENSSL_init_crypto, uint64_t opts, opts, const OPENSSL_INIT_SETTINGS *settings, settings, return 0, return)
 DEFINEFUNC(BIO *, BIO_new, const BIO_METHOD *a, a, return nullptr, return)
 DEFINEFUNC(const BIO_METHOD *, BIO_s_mem, void, DUMMYARG, return nullptr, return)
+#if !defined(LIBRESSL_VERSION_NUMBER) || LIBRESSL_VERSION_NUMBER >= 0x03050000fL
 DEFINEFUNC2(int, BN_is_word, BIGNUM *a, a, BN_ULONG w, w, return 0, return)
+#endif
 DEFINEFUNC(int, EVP_CIPHER_CTX_reset, EVP_CIPHER_CTX *c, c, return 0, return)
 DEFINEFUNC(int, EVP_PKEY_up_ref, EVP_PKEY *a, a, return 0, return)
+#ifdef OPENSSL_NO_DEPRECATED_3_0
 DEFINEFUNC2(EVP_PKEY_CTX *, EVP_PKEY_CTX_new, EVP_PKEY *pkey, pkey, ENGINE *e, e, return nullptr, return)
 DEFINEFUNC(int, EVP_PKEY_param_check, EVP_PKEY_CTX *ctx, ctx, return 0, return)
 DEFINEFUNC(void, EVP_PKEY_CTX_free, EVP_PKEY_CTX *ctx, ctx, return, return)
+#endif // OPENSSL_NO_DEPRECATED_3_0
 DEFINEFUNC(int, RSA_bits, RSA *a, a, return 0, return)
+#if !defined(LIBRESSL_VERSION_NUMBER) || LIBRESSL_VERSION_NUMBER >= 0x03050000fL
 DEFINEFUNC(int, DSA_bits, DSA *a, a, return 0, return)
 DEFINEFUNC(int, OPENSSL_sk_num, OPENSSL_STACK *a, a, return -1, return)
 DEFINEFUNC2(void, OPENSSL_sk_pop_free, OPENSSL_STACK *a, a, void (*b)(void*), b, return, DUMMYARG)
@@ -158,8 +163,18 @@ DEFINEFUNC(void, OPENSSL_sk_free, OPENSSL_STACK *a, a,
 DEFINEFUNC2(void *, OPENSSL_sk_value, OPENSSL_STACK *a, a, int b, b, return nullptr, return)
 DEFINEFUNC(int, SSL_session_reused, SSL *a, a, return 0, return)
 DEFINEFUNC2(unsigned long, SSL_CTX_set_options, SSL_CTX *ctx, ctx, unsigned long op, op, return 0, return)
+#else
+DEFINEFUNC(int, sk_num, STACK *a, a, return -1, return)
+DEFINEFUNC2(void, sk_pop_free, STACK *a, a, void (*b)(void*), b, return, DUMMYARG)
+DEFINEFUNC(_STACK *, sk_new_null, DUMMYARG, DUMMYARG, return nullptr, return)
+DEFINEFUNC2(void, sk_push, _STACK *a, a, void *b, b, return, DUMMYARG)
+DEFINEFUNC(void, sk_free, _STACK *a, a, return, DUMMYARG)
+DEFINEFUNC2(void *, sk_value, STACK *a, a, int b, b, return nullptr, return)
+#endif // LIBRESSL_VERSION_NUMBER
+#ifdef SSL_SECOP_PEER
 DEFINEFUNC(int, SSL_CTX_get_security_level, const SSL_CTX *ctx, ctx, return -1, return)
 DEFINEFUNC2(void, SSL_CTX_set_security_level, SSL_CTX *ctx, ctx, int level, level, return, return)
+#endif //SSL_SECOP_PEER
 #ifdef TLS1_3_VERSION
 DEFINEFUNC2(int, SSL_CTX_set_ciphersuites, SSL_CTX *ctx, ctx, const char *str, str, return 0, return)
 DEFINEFUNC2(void, SSL_set_psk_use_session_callback, SSL *ssl, ssl, q_SSL_psk_use_session_cb_func_t callback, callback, return, DUMMYARG)
@@ -169,7 +184,9 @@ DEFINEFUNC(int, SSL_SESSION_is_resumable, const SSL_SE
 DEFINEFUNC3(size_t, SSL_get_client_random, SSL *a, a, unsigned char *out, out, size_t outlen, outlen, return 0, return)
 DEFINEFUNC3(size_t, SSL_SESSION_get_master_key, const SSL_SESSION *ses, ses, unsigned char *out, out, size_t outlen, outlen, return 0, return)
 DEFINEFUNC6(int, CRYPTO_get_ex_new_index, int class_index, class_index, long argl, argl, void *argp, argp, CRYPTO_EX_new *new_func, new_func, CRYPTO_EX_dup *dup_func, dup_func, CRYPTO_EX_free *free_func, free_func, return -1, return)
+#ifndef LIBRESSL_VERSION_NUMBER
 DEFINEFUNC2(unsigned long, SSL_set_options, SSL *ssl, ssl, unsigned long op, op, return 0, return)
+#endif
 
 DEFINEFUNC(const SSL_METHOD *, TLS_method, DUMMYARG, DUMMYARG, return nullptr, return)
 DEFINEFUNC(const SSL_METHOD *, TLS_client_method, DUMMYARG, DUMMYARG, return nullptr, return)
@@ -183,7 +200,11 @@ DEFINEFUNC2(void, X509_STORE_set_verify_cb, X509_STORE
 DEFINEFUNC3(int, X509_STORE_set_ex_data, X509_STORE *a, a, int idx, idx, void *data, data, return 0, return)
 DEFINEFUNC2(void *, X509_STORE_get_ex_data, X509_STORE *r, r, int idx, idx, return nullptr, return)
 DEFINEFUNC(STACK_OF(X509) *, X509_STORE_CTX_get0_chain, X509_STORE_CTX *a, a, return nullptr, return)
+#ifndef LIBRESSL_VERSION_NUMBER
 DEFINEFUNC3(void, CRYPTO_free, void *str, str, const char *file, file, int line, line, return, DUMMYARG)
+#else
+DEFINEFUNC(void, CRYPTO_free, void *a, a, return, DUMMYARG)
+#endif
 DEFINEFUNC(long, OpenSSL_version_num, void, DUMMYARG, return 0, return)
 DEFINEFUNC(const char *, OpenSSL_version, int a, a, return nullptr, return)
 DEFINEFUNC(unsigned long, SSL_SESSION_get_ticket_lifetime_hint, const SSL_SESSION *session, session, return 0, return)
@@ -223,7 +244,9 @@ DEFINEFUNC5(int, OCSP_id_get0_info, ASN1_OCTET_STRING 
             ASN1_OCTET_STRING **piKeyHash, piKeyHash, ASN1_INTEGER **pserial, pserial, OCSP_CERTID *cid, cid,
             return 0, return)
 DEFINEFUNC2(OCSP_RESPONSE *, OCSP_response_create, int status, status, OCSP_BASICRESP *bs, bs, return nullptr, return)
+#if !defined(LIBRESSL_VERSION_NUMBER) || LIBRESSL_VERSION_NUMBER >= 0x03050000fL
 DEFINEFUNC(const STACK_OF(X509) *, OCSP_resp_get0_certs, const OCSP_BASICRESP *bs, bs, return nullptr, return)
+#endif
 DEFINEFUNC2(int, OCSP_id_cmp, OCSP_CERTID *a, a, OCSP_CERTID *b, b, return -1, return)
 DEFINEFUNC7(OCSP_SINGLERESP *, OCSP_basic_add1_status, OCSP_BASICRESP *r, r, OCSP_CERTID *c, c, int s, s,
             int re, re, ASN1_TIME *rt, rt, ASN1_TIME *t, t, ASN1_TIME *n, n, return nullptr, return)
@@ -355,12 +378,14 @@ DEFINEFUNC2(int, SSL_CTX_use_PrivateKey, SSL_CTX *a, a
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
@@ -385,7 +410,11 @@ DEFINEFUNC3(void, SSL_set_bio, SSL *a, a, BIO *b, b, B
 DEFINEFUNC(void, SSL_set_accept_state, SSL *a, a, return, DUMMYARG)
 DEFINEFUNC(void, SSL_set_connect_state, SSL *a, a, return, DUMMYARG)
 DEFINEFUNC(int, SSL_shutdown, SSL *a, a, return -1, return)
+#ifndef LIBRESSL_VERSION_NUMBER
 DEFINEFUNC(int, SSL_in_init, const SSL *a, a, return 0, return)
+#else
+DEFINEFUNC(int, SSL_state, const SSL *a, a, return 0, return)
+#endif
 DEFINEFUNC(int, SSL_get_shutdown, const SSL *ssl, ssl, return 0, return)
 DEFINEFUNC2(int, SSL_set_session, SSL* to, to, SSL_SESSION *session, session, return -1, return)
 DEFINEFUNC(void, SSL_SESSION_free, SSL_SESSION *ses, ses, return, DUMMYARG)
@@ -854,20 +883,35 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(ASN1_STRING_get0_data)
     RESOLVEFUNC(EVP_CIPHER_CTX_reset)
     RESOLVEFUNC(EVP_PKEY_up_ref)
+#ifdef OPENSSL_NO_DEPRECATED_3_0
     RESOLVEFUNC(EVP_PKEY_CTX_new)
     RESOLVEFUNC(EVP_PKEY_param_check)
     RESOLVEFUNC(EVP_PKEY_CTX_free)
+#endif // OPENSSL_NO_DEPRECATED_3_0
     RESOLVEFUNC(RSA_bits)
+#if !defined(LIBRESSL_VERSION_NUMBER) || LIBRESSL_VERSION_NUMBER >= 0x03050000fL
     RESOLVEFUNC(OPENSSL_sk_new_null)
     RESOLVEFUNC(OPENSSL_sk_push)
     RESOLVEFUNC(OPENSSL_sk_free)
     RESOLVEFUNC(OPENSSL_sk_num)
     RESOLVEFUNC(OPENSSL_sk_pop_free)
     RESOLVEFUNC(OPENSSL_sk_value)
+#else
+    RESOLVEFUNC(sk_new_null)
+    RESOLVEFUNC(sk_push)
+    RESOLVEFUNC(sk_free)
+    RESOLVEFUNC(sk_num)
+    RESOLVEFUNC(sk_pop_free)
+    RESOLVEFUNC(sk_value)
+#endif
     RESOLVEFUNC(DH_get0_pqg)
+#ifndef LIBRESSL_VERSION_NUMBER
     RESOLVEFUNC(SSL_CTX_set_options)
+#endif
+#ifdef SSL_SECOP_PEER
     RESOLVEFUNC(SSL_CTX_get_security_level)
     RESOLVEFUNC(SSL_CTX_set_security_level)
+#endif //SSL_SECOP_PEER
 #ifdef TLS1_3_VERSION
     RESOLVEFUNC(SSL_CTX_set_ciphersuites)
     RESOLVEFUNC(SSL_set_psk_use_session_callback)
@@ -877,9 +921,13 @@ bool q_resolveOpenSslSymbols()
 
     RESOLVEFUNC(SSL_get_client_random)
     RESOLVEFUNC(SSL_SESSION_get_master_key)
+#ifndef LIBRESSL_VERSION_NUMBER
     RESOLVEFUNC(SSL_session_reused)
+#endif
     RESOLVEFUNC(SSL_get_session)
+#ifndef LIBRESSL_VERSION_NUMBER
     RESOLVEFUNC(SSL_set_options)
+#endif
     RESOLVEFUNC(CRYPTO_get_ex_new_index)
     RESOLVEFUNC(TLS_method)
     RESOLVEFUNC(TLS_client_method)
@@ -906,7 +954,9 @@ bool q_resolveOpenSslSymbols()
 
     RESOLVEFUNC(SSL_SESSION_get_ticket_lifetime_hint)
     RESOLVEFUNC(DH_bits)
+#if !defined(LIBRESSL_VERSION_NUMBER) || LIBRESSL_VERSION_NUMBER >= 0x03050000fL
     RESOLVEFUNC(DSA_bits)
+#endif
 
 #if QT_CONFIG(dtls)
     RESOLVEFUNC(DTLSv1_listen)
@@ -936,7 +986,9 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(OCSP_check_validity)
     RESOLVEFUNC(OCSP_cert_to_id)
     RESOLVEFUNC(OCSP_id_get0_info)
+#if !defined(LIBRESSL_VERSION_NUMBER) || LIBRESSL_VERSION_NUMBER >= 0x03050000fL
     RESOLVEFUNC(OCSP_resp_get0_certs)
+#endif
     RESOLVEFUNC(OCSP_basic_sign)
     RESOLVEFUNC(OCSP_response_create)
     RESOLVEFUNC(i2d_OCSP_RESPONSE)
@@ -973,7 +1025,9 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(EC_GROUP_get_degree)
 #endif
     RESOLVEFUNC(BN_num_bits)
+#if !defined(LIBRESSL_VERSION_NUMBER) || LIBRESSL_VERSION_NUMBER >= 0x03050000fL
     RESOLVEFUNC(BN_is_word)
+#endif
     RESOLVEFUNC(BN_mod_word)
     RESOLVEFUNC(DSA_new)
     RESOLVEFUNC(DSA_free)
@@ -1066,12 +1120,14 @@ bool q_resolveOpenSslSymbols()
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
@@ -1099,7 +1155,11 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(SSL_set_bio)
     RESOLVEFUNC(SSL_set_connect_state)
     RESOLVEFUNC(SSL_shutdown)
+#ifndef LIBRESSL_VERSION_NUMBER
     RESOLVEFUNC(SSL_in_init)
+#else
+    RESOLVEFUNC(SSL_state)
+#endif
     RESOLVEFUNC(SSL_get_shutdown)
     RESOLVEFUNC(SSL_set_session)
     RESOLVEFUNC(SSL_SESSION_free)
