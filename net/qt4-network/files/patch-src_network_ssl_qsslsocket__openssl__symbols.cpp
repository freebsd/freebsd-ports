--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2015-05-07 14:14:44 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -117,9 +117,11 @@ DEFINEFUNC3(int, BIO_read, BIO *a, a, void *b, b, int 
 DEFINEFUNC(BIO_METHOD *, BIO_s_mem, void, DUMMYARG, return 0, return)
 DEFINEFUNC3(int, BIO_write, BIO *a, a, const void *b, b, int c, c, return -1, return)
 DEFINEFUNC(int, BN_num_bits, const BIGNUM *a, a, return 0, return)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 DEFINEFUNC(int, CRYPTO_num_locks, DUMMYARG, DUMMYARG, return 0, return)
 DEFINEFUNC(void, CRYPTO_set_locking_callback, void (*a)(int, int, const char *, int), a, return, DUMMYARG)
 DEFINEFUNC(void, CRYPTO_set_id_callback, unsigned long (*a)(), a, return, DUMMYARG)
+#endif
 DEFINEFUNC(void, CRYPTO_free, void *a, a, return, DUMMYARG)
 DEFINEFUNC(void, DSA_free, DSA *a, a, return, DUMMYARG)
 #if  OPENSSL_VERSION_NUMBER < 0x00908000L
@@ -157,6 +159,7 @@ DEFINEFUNC2(int, PEM_write_bio_RSA_PUBKEY, BIO *a, a, 
 DEFINEFUNC2(void, RAND_seed, const void *a, a, int b, b, return, DUMMYARG)
 DEFINEFUNC(int, RAND_status, void, DUMMYARG, return -1, return)
 DEFINEFUNC(void, RSA_free, RSA *a, a, return, DUMMYARG)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 DEFINEFUNC(int, sk_num, STACK *a, a, return -1, return)
 DEFINEFUNC2(void, sk_pop_free, STACK *a, a, void (*b)(void*), b, return, DUMMYARG)
 #if OPENSSL_VERSION_NUMBER >= 0x10000000L
@@ -166,6 +169,12 @@ DEFINEFUNC2(void *, sk_value, STACK *a, a, int b, b, r
 DEFINEFUNC(void, sk_free, STACK *a, a, return, DUMMYARG)
 DEFINEFUNC2(char *, sk_value, STACK *a, a, int b, b, return 0, return)
 #endif
+#else
+DEFINEFUNC(int, OPENSSL_sk_num, STACK *a, a, return -1, return)
+DEFINEFUNC2(void, OPENSSL_sk_pop_free, STACK *a, a, void (*b)(void*), b, return, DUMMYARG)
+DEFINEFUNC(void, OPENSSL_sk_free, _STACK *a, a, return, DUMMYARG)
+DEFINEFUNC2(void *, OPENSSL_sk_value, STACK *a, a, int b, b, return 0, return)
+#endif
 DEFINEFUNC(int, SSL_accept, SSL *a, a, return -1, return)
 DEFINEFUNC(int, SSL_clear, SSL *a, a, return -1, return)
 DEFINEFUNC3(char *, SSL_CIPHER_description, SSL_CIPHER *a, a, char *b, b, int c, c, return 0, return)
@@ -213,8 +222,12 @@ DEFINEFUNC(long, SSL_get_verify_result, const SSL *a, 
 #else
 DEFINEFUNC(long, SSL_get_verify_result, SSL *a, a, return -1, return)
 #endif
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 DEFINEFUNC(int, SSL_library_init, void, DUMMYARG, return -1, return)
 DEFINEFUNC(void, SSL_load_error_strings, void, DUMMYARG, return, DUMMYARG)
+#else
+DEFINEFUNC2(int, OPENSSL_init_ssl, uint64_t opts, opts, void *settings, settings, return -1, return)
+#endif
 DEFINEFUNC(SSL *, SSL_new, SSL_CTX *a, a, return 0, return)
 #if OPENSSL_VERSION_NUMBER >= 0x0090806fL && !defined(OPENSSL_NO_TLSEXT)
 DEFINEFUNC4(long, SSL_ctrl, SSL *a, a, int cmd, cmd, long larg, larg, void *parg, parg, return -1, return)
@@ -229,13 +242,21 @@ DEFINEFUNC(int, SSL_shutdown, SSL *a, a, return -1, re
 DEFINEFUNC(const SSL_METHOD *, SSLv2_client_method, DUMMYARG, DUMMYARG, return 0, return)
 #endif
 DEFINEFUNC(const SSL_METHOD *, SSLv3_client_method, DUMMYARG, DUMMYARG, return 0, return)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 DEFINEFUNC(const SSL_METHOD *, SSLv23_client_method, DUMMYARG, DUMMYARG, return 0, return)
+#else
+DEFINEFUNC(const SSL_METHOD *, TLS_client_method, DUMMYARG, DUMMYARG, return 0, return)
+#endif
 DEFINEFUNC(const SSL_METHOD *, TLSv1_client_method, DUMMYARG, DUMMYARG, return 0, return)
 #ifndef OPENSSL_NO_SSL2
 DEFINEFUNC(const SSL_METHOD *, SSLv2_server_method, DUMMYARG, DUMMYARG, return 0, return)
 #endif
 DEFINEFUNC(const SSL_METHOD *, SSLv3_server_method, DUMMYARG, DUMMYARG, return 0, return)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 DEFINEFUNC(const SSL_METHOD *, SSLv23_server_method, DUMMYARG, DUMMYARG, return 0, return)
+#else
+DEFINEFUNC(const SSL_METHOD *, TLS_server_method, DUMMYARG, DUMMYARG, return 0, return)
+#endif
 DEFINEFUNC(const SSL_METHOD *, TLSv1_server_method, DUMMYARG, DUMMYARG, return 0, return)
 #else
 DEFINEFUNC(SSL_METHOD *, SSLv2_client_method, DUMMYARG, DUMMYARG, return 0, return)
@@ -274,7 +295,11 @@ DEFINEFUNC2(int, X509_STORE_CTX_set_purpose, X509_STOR
 DEFINEFUNC(int, X509_STORE_CTX_get_error, X509_STORE_CTX *a, a, return -1, return)
 DEFINEFUNC(int, X509_STORE_CTX_get_error_depth, X509_STORE_CTX *a, a, return -1, return)
 DEFINEFUNC(X509 *, X509_STORE_CTX_get_current_cert, X509_STORE_CTX *a, a, return 0, return)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 DEFINEFUNC(STACK_OF(X509) *, X509_STORE_CTX_get_chain, X509_STORE_CTX *a, a, return 0, return)
+#else
+DEFINEFUNC(STACK_OF(X509) *, X509_STORE_CTX_get0_chain, X509_STORE_CTX *a, a, return 0, return)
+#endif
 DEFINEFUNC(X509_STORE_CTX *, X509_STORE_CTX_new, DUMMYARG, DUMMYARG, return 0, return)
 #ifdef SSLEAY_MACROS
 DEFINEFUNC2(int, i2d_DSAPrivateKey, const DSA *a, a, unsigned char **b, b, return -1, return)
@@ -282,11 +307,35 @@ DEFINEFUNC2(int, i2d_RSAPrivateKey, const RSA *a, a, u
 DEFINEFUNC3(RSA *, d2i_RSAPrivateKey, RSA **a, a, unsigned char **b, b, long c, c, return 0, return)
 DEFINEFUNC3(DSA *, d2i_DSAPrivateKey, DSA **a, a, unsigned char **b, b, long c, c, return 0, return)
 #endif
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 DEFINEFUNC(void, OPENSSL_add_all_algorithms_noconf, void, DUMMYARG, return, DUMMYARG)
 DEFINEFUNC(void, OPENSSL_add_all_algorithms_conf, void, DUMMYARG, return, DUMMYARG)
+#else
+DEFINEFUNC2(int, OPENSSL_init_crypto, uint64_t opts, opts, void *settings, settings, return -1, return)
+#endif
 DEFINEFUNC3(int, SSL_CTX_load_verify_locations, SSL_CTX *ctx, ctx, const char *CAfile, CAfile, const char *CApath, CApath, return 0, return)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 DEFINEFUNC(long, SSLeay, void, DUMMYARG, return 0, return)
+#else
+DEFINEFUNC(unsigned long, OpenSSL_version_num, void, DUMMYARG, return 0, return)
+#endif
+DEFINEFUNC(X509_STORE *, SSL_CTX_get_cert_store, const SSL_CTX *ctx, ctx, return 0, return)
 
+DEFINEFUNC(ASN1_INTEGER *, X509_get_serialNumber, X509 *x, x, return 0, return)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+DEFINEFUNC(int, EVP_PKEY_id, const EVP_PKEY *pkey, pkey, return 0, return)
+DEFINEFUNC(int, EVP_PKEY_base_id, const EVP_PKEY *pkey, pkey, return 0, return)
+DEFINEFUNC2(int, SSL_CIPHER_get_bits, const SSL_CIPHER *cipher, cipher, int *alg_bits, alg_bits, return 0, return)
+DEFINEFUNC2(long, SSL_CTX_set_options, SSL_CTX *ctx, ctx, long options, options, return 0, return)
+DEFINEFUNC(long, X509_get_version, X509 *x, x, return 0, return)
+DEFINEFUNC(X509_PUBKEY *, X509_get_X509_PUBKEY, X509 *x, x, return 0, return)
+DEFINEFUNC(int, RSA_bits,  const RSA *rsa, rsa, return 0, return)
+DEFINEFUNC(int, DSA_security_bits, const DSA *dsa, dsa, return 0, return)
+DEFINEFUNC(ASN1_TIME *, X509_getm_notAfter, X509 *x, x, return 0, return)
+DEFINEFUNC(ASN1_TIME *, X509_getm_notBefore, X509 *x, x, return 0, return)
+DEFINEFUNC4(void, DSA_get0_pqg, const DSA *d, d, BIGNUM **p, p, BIGNUM **q, q, BIGNUM **g, g, return, return)
+#endif
+
 #ifdef Q_OS_SYMBIAN
 #define RESOLVEFUNC(func, ordinal, lib) \
     if (!(_q_##func = _q_PTR_##func(lib->resolve(#ordinal)))) \
@@ -511,9 +560,9 @@ static QPair<QLibrary*, QLibrary*> loadOpenSsl()
     libcrypto->setLoadHints(libcrypto->loadHints() | QLibrary::ImprovedSearchHeuristics);
 #elif defined(SHLIB_VERSION_NUMBER)
     // first attempt: the canonical name is libssl.so.<SHLIB_VERSION_NUMBER>
-    libssl->setFileNameAndVersion(QLatin1String("ssl"), QLatin1String(SHLIB_VERSION_NUMBER));
+    libssl->setFileNameAndVersion(QLatin1String("%%OPENSSLLIB%%/libssl"), QLatin1String(SHLIB_VERSION_NUMBER));
     libssl->setLoadHints(QLibrary::ImprovedSearchHeuristics);
-    libcrypto->setFileNameAndVersion(QLatin1String("crypto"), QLatin1String(SHLIB_VERSION_NUMBER));
+    libcrypto->setFileNameAndVersion(QLatin1String("%%OPENSSLLIB%%/libcrypto"), QLatin1String(SHLIB_VERSION_NUMBER));
     libcrypto->setLoadHints(libcrypto->loadHints() | QLibrary::ImprovedSearchHeuristics);
     if (libcrypto->load() && libssl->load()) {
         // libssl.so.<SHLIB_VERSION_NUMBER> and libcrypto.so.<SHLIB_VERSION_NUMBER> found
@@ -525,8 +574,8 @@ static QPair<QLibrary*, QLibrary*> loadOpenSsl()
 #endif
 
     // second attempt: find the development files libssl.so and libcrypto.so
-    libssl->setFileNameAndVersion(QLatin1String("ssl"), -1);
-    libcrypto->setFileNameAndVersion(QLatin1String("crypto"), -1);
+    libssl->setFileNameAndVersion(QLatin1String("%%OPENSSLLIB%%/libssl"), -1);
+    libcrypto->setFileNameAndVersion(QLatin1String("%%OPENSSLLIB%%/libcrypto"), -1);
     if (libcrypto->load() && libssl->load()) {
         // libssl.so.0 and libcrypto.so.0 found
         return pair;
@@ -580,8 +629,12 @@ bool q_resolveOpenSslSymbols()
     static volatile bool symbolsResolved = false;
     static volatile bool triedToResolveSymbols = false;
 #ifndef QT_NO_THREAD
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     QMutexLocker locker(QMutexPool::globalInstanceGet((void *)&q_SSL_library_init));
+#else
+    QMutexLocker locker(QMutexPool::globalInstanceGet((void *)&q_OPENSSL_init_ssl));
 #endif
+#endif
     if (symbolsResolved)
         return true;
     if (triedToResolveSymbols)
@@ -614,9 +667,11 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(BIO_write, 269, libs.second )
     RESOLVEFUNC(BN_num_bits, 387, libs.second )
     RESOLVEFUNC(CRYPTO_free, 469, libs.second )
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     RESOLVEFUNC(CRYPTO_num_locks, 500, libs.second )
     RESOLVEFUNC(CRYPTO_set_id_callback, 513, libs.second )
     RESOLVEFUNC(CRYPTO_set_locking_callback, 516, libs.second )
+#endif
     RESOLVEFUNC(DSA_free, 594, libs.second )
     RESOLVEFUNC(ERR_error_string, 744, libs.second )
     RESOLVEFUNC(ERR_get_error, 749, libs.second )
@@ -674,8 +729,10 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(SSL_get_peer_cert_chain, 117, libs.first )
     RESOLVEFUNC(SSL_get_peer_certificate, 118, libs.first )
     RESOLVEFUNC(SSL_get_verify_result, 132, libs.first )
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     RESOLVEFUNC(SSL_library_init, 137, libs.first )
     RESOLVEFUNC(SSL_load_error_strings, 139, libs.first )
+#endif
     RESOLVEFUNC(SSL_new, 140, libs.first )
 #if OPENSSL_VERSION_NUMBER >= 0x0090806fL && !defined(OPENSSL_NO_TLSEXT)
     RESOLVEFUNC(SSL_ctrl, 95, libs.first )
@@ -747,9 +804,11 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(BIO_write)
     RESOLVEFUNC(BN_num_bits)
     RESOLVEFUNC(CRYPTO_free)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     RESOLVEFUNC(CRYPTO_num_locks)
     RESOLVEFUNC(CRYPTO_set_id_callback)
     RESOLVEFUNC(CRYPTO_set_locking_callback)
+#endif
     RESOLVEFUNC(DSA_free)
     RESOLVEFUNC(ERR_error_string)
     RESOLVEFUNC(ERR_get_error)
@@ -779,10 +838,17 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(RAND_seed)
     RESOLVEFUNC(RAND_status)
     RESOLVEFUNC(RSA_free)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     RESOLVEFUNC(sk_free)
     RESOLVEFUNC(sk_num)
     RESOLVEFUNC(sk_pop_free)
     RESOLVEFUNC(sk_value)
+#else
+    RESOLVEFUNC(OPENSSL_sk_free)
+    RESOLVEFUNC(OPENSSL_sk_num)
+    RESOLVEFUNC(OPENSSL_sk_pop_free)
+    RESOLVEFUNC(OPENSSL_sk_value)
+#endif
     RESOLVEFUNC(SSL_CIPHER_description)
     RESOLVEFUNC(SSL_CTX_check_private_key)
     RESOLVEFUNC(SSL_CTX_ctrl)
@@ -797,6 +863,7 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(SSL_CTX_use_PrivateKey)
     RESOLVEFUNC(SSL_CTX_use_RSAPrivateKey)
     RESOLVEFUNC(SSL_CTX_use_PrivateKey_file)
+    RESOLVEFUNC(SSL_CTX_get_cert_store)
     RESOLVEFUNC(SSL_accept)
     RESOLVEFUNC(SSL_clear)
     RESOLVEFUNC(SSL_connect)
@@ -807,8 +874,12 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(SSL_get_peer_cert_chain)
     RESOLVEFUNC(SSL_get_peer_certificate)
     RESOLVEFUNC(SSL_get_verify_result)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     RESOLVEFUNC(SSL_library_init)
     RESOLVEFUNC(SSL_load_error_strings)
+#else
+    RESOLVEFUNC(OPENSSL_init_ssl)
+#endif
     RESOLVEFUNC(SSL_new)
 #if OPENSSL_VERSION_NUMBER >= 0x0090806fL && !defined(OPENSSL_NO_TLSEXT)
     RESOLVEFUNC(SSL_ctrl)
@@ -819,17 +890,42 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(SSL_set_connect_state)
     RESOLVEFUNC(SSL_shutdown)
     RESOLVEFUNC(SSL_write)
+
+    RESOLVEFUNC(X509_get_serialNumber)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    RESOLVEFUNC(SSL_CTX_ctrl)
+    RESOLVEFUNC(EVP_PKEY_id)
+    RESOLVEFUNC(EVP_PKEY_base_id)
+    RESOLVEFUNC(SSL_CIPHER_get_bits)
+    RESOLVEFUNC(SSL_CTX_set_options)
+    RESOLVEFUNC(X509_get_version)
+    RESOLVEFUNC(X509_get_X509_PUBKEY)
+    RESOLVEFUNC(RSA_bits)
+    RESOLVEFUNC(DSA_security_bits)
+    RESOLVEFUNC(X509_getm_notAfter)
+    RESOLVEFUNC(X509_getm_notBefore)
+    RESOLVEFUNC(DSA_get0_pqg)
+#endif
+
 #ifndef OPENSSL_NO_SSL2
     RESOLVEFUNC(SSLv2_client_method)
 #endif
     RESOLVEFUNC(SSLv3_client_method)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     RESOLVEFUNC(SSLv23_client_method)
+#else
+    RESOLVEFUNC(TLS_client_method)
+#endif
     RESOLVEFUNC(TLSv1_client_method)
 #ifndef OPENSSL_NO_SSL2
     RESOLVEFUNC(SSLv2_server_method)
 #endif
     RESOLVEFUNC(SSLv3_server_method)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     RESOLVEFUNC(SSLv23_server_method)
+#else
+    RESOLVEFUNC(TLS_server_method)
+#endif
     RESOLVEFUNC(TLSv1_server_method)
     RESOLVEFUNC(X509_NAME_entry_count)
     RESOLVEFUNC(X509_NAME_get_entry)
@@ -846,7 +942,11 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(X509_STORE_CTX_get_error)
     RESOLVEFUNC(X509_STORE_CTX_get_error_depth)
     RESOLVEFUNC(X509_STORE_CTX_get_current_cert)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     RESOLVEFUNC(X509_STORE_CTX_get_chain)
+#else
+    RESOLVEFUNC(X509_STORE_CTX_get0_chain)
+#endif
     RESOLVEFUNC(X509_cmp)
 #ifndef SSLEAY_MACROS
     RESOLVEFUNC(X509_dup)
@@ -867,10 +967,18 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(d2i_DSAPrivateKey)
     RESOLVEFUNC(d2i_RSAPrivateKey)
 #endif
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     RESOLVEFUNC(OPENSSL_add_all_algorithms_noconf)
     RESOLVEFUNC(OPENSSL_add_all_algorithms_conf)
+#else
+    RESOLVEFUNC(OPENSSL_init_crypto)
+#endif
     RESOLVEFUNC(SSL_CTX_load_verify_locations)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     RESOLVEFUNC(SSLeay)
+#else
+    RESOLVEFUNC(OpenSSL_version_num)
+#endif
 #endif // Q_OS_SYMBIAN
     symbolsResolved = true;
     delete libs.first;
