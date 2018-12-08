--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2015-05-07 14:14:44 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols_p.h
@@ -213,9 +213,15 @@ int q_BIO_read(BIO *a, void *b, int c);
 BIO_METHOD *q_BIO_s_mem();
 int q_BIO_write(BIO *a, const void *b, int c);
 int q_BN_num_bits(const BIGNUM *a);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 int q_CRYPTO_num_locks();
 void q_CRYPTO_set_locking_callback(void (*a)(int, int, const char *, int));
 void q_CRYPTO_set_id_callback(unsigned long (*a)());
+#else
+#define q_CRYPTO_num_locks() 1
+#define q_CRYPTO_set_locking_callback(a)
+#define q_CRYPTO_set_id_callback(a)
+#endif
 void q_CRYPTO_free(void *a);
 void q_DSA_free(DSA *a);
 #if OPENSSL_VERSION_NUMBER >= 0x00908000L
@@ -258,6 +264,7 @@ int q_PEM_write_bio_RSA_PUBKEY(BIO *a, RSA *b);
 void q_RAND_seed(const void *a, int b);
 int q_RAND_status();
 void q_RSA_free(RSA *a);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 int q_sk_num(STACK *a);
 void q_sk_pop_free(STACK *a, void (*b)(void *));
 #if OPENSSL_VERSION_NUMBER >= 0x10000000L
@@ -267,6 +274,16 @@ void * q_sk_value(STACK *a, int b);
 void q_sk_free(STACK *a);
 char * q_sk_value(STACK *a, int b);
 #endif
+#else
+int q_OPENSSL_sk_num(STACK *a);
+void q_OPENSSL_sk_pop_free(STACK *a, void (*b)(void *));
+void q_OPENSSL_sk_free(_STACK *a);
+void * q_OPENSSL_sk_value(STACK *a, int b);
+#define q_sk_num q_OPENSSL_sk_num
+#define q_sk_pop_free q_OPENSSL_sk_pop_free
+#define q_sk_free q_OPENSSL_sk_free
+#define q_sk_value q_OPENSSL_sk_value
+#endif
 int q_SSL_accept(SSL *a);
 int q_SSL_clear(SSL *a);
 char *q_SSL_CIPHER_description(SSL_CIPHER *a, char *b, int c);
@@ -314,8 +331,14 @@ long q_SSL_get_verify_result(const SSL *a);
 #else
 long q_SSL_get_verify_result(SSL *a);
 #endif
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 int q_SSL_library_init();
 void q_SSL_load_error_strings();
+#else
+int q_OPENSSL_init_ssl(uint64_t opts, void *settings);
+#define q_SSL_library_init() q_OPENSSL_init_ssl(0, NULL)
+#define q_SSL_load_error_strings() q_OPENSSL_init_ssl(OPENSSL_INIT_LOAD_SSL_STRINGS | OPENSSL_INIT_LOAD_CRYPTO_STRINGS, NULL)
+#endif
 SSL *q_SSL_new(SSL_CTX *a);
 #if OPENSSL_VERSION_NUMBER >= 0x0090806fL && !defined(OPENSSL_NO_TLSEXT)
 long q_SSL_ctrl(SSL *ssl,int cmd, long larg, void *parg);
@@ -328,11 +351,21 @@ int q_SSL_shutdown(SSL *a);
 #if OPENSSL_VERSION_NUMBER >= 0x10000000L
 const SSL_METHOD *q_SSLv2_client_method();
 const SSL_METHOD *q_SSLv3_client_method();
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 const SSL_METHOD *q_SSLv23_client_method();
+#else
+const SSL_METHOD *q_TLS_client_method();
+#define q_SSLv23_client_method q_TLS_client_method
+#endif
 const SSL_METHOD *q_TLSv1_client_method();
 const SSL_METHOD *q_SSLv2_server_method();
 const SSL_METHOD *q_SSLv3_server_method();
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 const SSL_METHOD *q_SSLv23_server_method();
+#else
+const SSL_METHOD *q_TLS_server_method();
+#define q_SSLv23_server_method q_TLS_server_method
+#endif
 const SSL_METHOD *q_TLSv1_server_method();
 #else
 SSL_METHOD *q_SSLv2_client_method();
@@ -377,7 +410,12 @@ int q_X509_STORE_CTX_set_purpose(X509_STORE_CTX *ctx, 
 int q_X509_STORE_CTX_get_error(X509_STORE_CTX *ctx);
 int q_X509_STORE_CTX_get_error_depth(X509_STORE_CTX *ctx);
 X509 *q_X509_STORE_CTX_get_current_cert(X509_STORE_CTX *ctx);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 STACK_OF(X509) *q_X509_STORE_CTX_get_chain(X509_STORE_CTX *ctx);
+#else
+STACK_OF(X509) *q_X509_STORE_CTX_get0_chain(X509_STORE_CTX *ctx);
+#define q_X509_STORE_CTX_get_chain q_X509_STORE_CTX_get0_chain
+#endif
 
 #define q_BIO_get_mem_data(b, pp) (int)q_BIO_ctrl(b,BIO_CTRL_INFO,0,(char *)pp)
 #define q_BIO_pending(b) (int)q_BIO_ctrl(b,BIO_CTRL_PENDING,0,NULL)
@@ -399,7 +437,24 @@ DSA *q_d2i_DSAPrivateKey(DSA **a, unsigned char **pp, 
 		PEM_ASN1_write_bio((int (*)(void*, unsigned char**))q_i2d_DSAPrivateKey,PEM_STRING_DSA,\
 			bp,(char *)x,enc,kstr,klen,cb,u)
 #endif
+
+X509_STORE * q_SSL_CTX_get_cert_store(const SSL_CTX *ctx);
+ASN1_INTEGER * q_X509_get_serialNumber(X509 *x);
+
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 #define q_SSL_CTX_set_options(ctx,op) q_SSL_CTX_ctrl((ctx),SSL_CTRL_OPTIONS,(op),NULL)
+#else
+int q_EVP_PKEY_id(const EVP_PKEY *pkey);
+int q_EVP_PKEY_base_id(const EVP_PKEY *pkey);
+int q_SSL_CIPHER_get_bits(const SSL_CIPHER *cipher, int *alg_bits);
+long q_SSL_CTX_set_options(SSL_CTX *ctx, long options);
+long q_X509_get_version(X509 *x);
+X509_PUBKEY * q_X509_get_X509_PUBKEY(X509 *x);
+int q_RSA_bits(const RSA *rsa);
+int q_DSA_security_bits(const DSA *dsa);
+void q_DSA_get0_pqg(const DSA *d, BIGNUM **p, BIGNUM **q, BIGNUM **g);
+#endif
+
 #define q_SKM_sk_num(type, st) ((int (*)(const STACK_OF(type) *))q_sk_num)(st)
 #define q_SKM_sk_value(type, st,i) ((type * (*)(const STACK_OF(type) *, int))q_sk_value)(st, i)
 #define q_sk_GENERAL_NAME_num(st) q_SKM_sk_num(GENERAL_NAME, (st))
@@ -410,8 +465,17 @@ DSA *q_d2i_DSAPrivateKey(DSA **a, unsigned char **pp, 
 #define q_sk_SSL_CIPHER_value(st, i) q_SKM_sk_value(SSL_CIPHER, (st), (i))
 #define q_SSL_CTX_add_extra_chain_cert(ctx,x509) \
         q_SSL_CTX_ctrl(ctx,SSL_CTRL_EXTRA_CHAIN_CERT,0,(char *)x509)
+
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 #define q_X509_get_notAfter(x) X509_get_notAfter(x)
 #define q_X509_get_notBefore(x) X509_get_notBefore(x)
+#else
+ASN1_TIME *q_X509_getm_notAfter(X509 *x);
+ASN1_TIME *q_X509_getm_notBefore(X509 *x);
+#define q_X509_get_notAfter(x) q_X509_getm_notAfter(x)
+#define q_X509_get_notBefore(x) q_X509_getm_notBefore(x)
+#endif
+
 #define q_EVP_PKEY_assign_RSA(pkey,rsa) q_EVP_PKEY_assign((pkey),EVP_PKEY_RSA,\
 					(char *)(rsa))
 #define q_EVP_PKEY_assign_DSA(pkey,dsa) q_EVP_PKEY_assign((pkey),EVP_PKEY_DSA,\
@@ -421,10 +485,21 @@ DSA *q_d2i_DSAPrivateKey(DSA **a, unsigned char **pp, 
 #else
 #define q_OpenSSL_add_all_algorithms() q_OPENSSL_add_all_algorithms_noconf()
 #endif
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 void q_OPENSSL_add_all_algorithms_noconf();
 void q_OPENSSL_add_all_algorithms_conf();
+#else
+int q_OPENSSL_init_crypto(uint64_t opts, void *settings);
+#define q_OPENSSL_add_all_algorithms_conf() q_OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS | OPENSSL_INIT_ADD_ALL_DIGESTS | OPENSSL_INIT_LOAD_CONFIG, NULL)
+#  define q_OPENSSL_add_all_algorithms_noconf() q_OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS | OPENSSL_INIT_ADD_ALL_DIGESTS, NULL)
+#endif
 int q_SSL_CTX_load_verify_locations(SSL_CTX *ctx, const char *CAfile, const char *CApath);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 long q_SSLeay();
+#else
+unsigned long q_OpenSSL_version_num();
+#define q_SSLeay q_OpenSSL_version_num
+#endif
 
 // Helper function
 class QDateTime;
