Patch from Gentoo: https://gitweb.gentoo.org/repo/gentoo.git/plain/dev-qt/qtnetwork/files/qtnetwork-5.15.1-libressl.patch
--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2020-09-02 10:15:07 UTC
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
@@ -230,20 +237,43 @@ const unsigned char * q_ASN1_STRING_get0_data(const AS
 Q_AUTOTEST_EXPORT BIO *q_BIO_new(const BIO_METHOD *a);
 Q_AUTOTEST_EXPORT const BIO_METHOD *q_BIO_s_mem();
 
+#ifndef LIBRESSL_VERSION_NUMBER
 int q_DSA_bits(DSA *a);
+#else
+#define q_DSA_bits(dsa) q_BN_num_bits((dsa)->p)
+#endif
 int q_EVP_CIPHER_CTX_reset(EVP_CIPHER_CTX *c);
 Q_AUTOTEST_EXPORT int q_EVP_PKEY_up_ref(EVP_PKEY *a);
+#ifdef OPENSSL_NO_DEPRECATED_3_0
 EVP_PKEY_CTX *q_EVP_PKEY_CTX_new(EVP_PKEY *pkey, ENGINE *e);
 void q_EVP_PKEY_CTX_free(EVP_PKEY_CTX *ctx);
 int q_EVP_PKEY_param_check(EVP_PKEY_CTX *ctx);
+#endif // OPENSSL_NO_DEPRECATED_3_0
 int q_EVP_PKEY_base_id(EVP_PKEY *a);
 int q_RSA_bits(RSA *a);
+
+#ifndef LIBRESSL_VERSION_NUMBER
 Q_AUTOTEST_EXPORT int q_OPENSSL_sk_num(OPENSSL_STACK *a);
 Q_AUTOTEST_EXPORT void q_OPENSSL_sk_pop_free(OPENSSL_STACK *a, void (*b)(void *));
 Q_AUTOTEST_EXPORT OPENSSL_STACK *q_OPENSSL_sk_new_null();
 Q_AUTOTEST_EXPORT void q_OPENSSL_sk_push(OPENSSL_STACK *st, void *data);
 Q_AUTOTEST_EXPORT void q_OPENSSL_sk_free(OPENSSL_STACK *a);
 Q_AUTOTEST_EXPORT void * q_OPENSSL_sk_value(OPENSSL_STACK *a, int b);
+#else // LIBRESSL_VERSION_NUMBER
+int q_sk_num(STACK *a);
+#define q_OPENSSL_sk_num(a) q_sk_num(a)
+void q_sk_pop_free(STACK *a, void (*b)(void *));
+#define q_OPENSSL_sk_pop_free(a, b) q_sk_pop_free(a, b)
+STACK *q_sk_new_null();
+#define q_OPENSSL_sk_new_null() q_sk_new_null()
+void q_sk_push(STACK *st, void *data);
+#define q_OPENSSL_sk_push(st, data) q_sk_push(st, data)
+void q_sk_free(STACK *a);
+#define q_OPENSSL_sk_free q_sk_free
+void *q_sk_value(STACK *a, int b);
+#define q_OPENSSL_sk_value(a, b) q_sk_value(a, b)
+#endif // LIBRESSL_VERSION_NUMBER
+
 int q_SSL_session_reused(SSL *a);
 unsigned long q_SSL_CTX_set_options(SSL_CTX *ctx, unsigned long op);
 int q_OPENSSL_init_ssl(uint64_t opts, const OPENSSL_INIT_SETTINGS *settings);
@@ -269,8 +299,13 @@ int q_DH_bits(DH *dh);
 # define q_SSL_load_error_strings() q_OPENSSL_init_ssl(OPENSSL_INIT_LOAD_SSL_STRINGS \
                                                        | OPENSSL_INIT_LOAD_CRYPTO_STRINGS, NULL)
 
+#ifndef LIBRESSL_VERSION_NUMBER
 #define q_SKM_sk_num(type, st) ((int (*)(const STACK_OF(type) *))q_OPENSSL_sk_num)(st)
 #define q_SKM_sk_value(type, st,i) ((type * (*)(const STACK_OF(type) *, int))q_OPENSSL_sk_value)(st, i)
+#else
+#define q_SKM_sk_num(type, st) ((int (*)(const STACK_OF(type) *))q_sk_num)(st)
+#define q_SKM_sk_value(type, st,i) ((type * (*)(const STACK_OF(type) *, int))q_sk_value)(st, i)
+#endif // LIBRESSL_VERSION_NUMBER
 
 #define q_OPENSSL_add_all_algorithms_conf()  q_OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS \
                                                                    | OPENSSL_INIT_ADD_ALL_DIGESTS \
@@ -279,7 +314,11 @@ int q_DH_bits(DH *dh);
                                                                     | OPENSSL_INIT_ADD_ALL_DIGESTS, NULL)
 
 int q_OPENSSL_init_crypto(uint64_t opts, const OPENSSL_INIT_SETTINGS *settings);
+#ifndef LIBRESSL_VERSION_NUMBER
 void q_CRYPTO_free(void *str, const char *file, int line);
+#else
+void q_CRYPTO_free(void *a);
+#endif
 
 long q_OpenSSL_version_num();
 const char *q_OpenSSL_version(int type);
@@ -497,12 +536,14 @@ int q_SSL_CTX_use_PrivateKey(SSL_CTX *a, EVP_PKEY *b);
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
@@ -728,7 +769,11 @@ int q_OCSP_check_validity(ASN1_GENERALIZEDTIME *thisup
 int q_OCSP_id_get0_info(ASN1_OCTET_STRING **piNameHash, ASN1_OBJECT **pmd, ASN1_OCTET_STRING **pikeyHash,
                         ASN1_INTEGER **pserial, OCSP_CERTID *cid);
 
+#ifndef LIBRESSL_VERSION_NUMBER
 const STACK_OF(X509) *q_OCSP_resp_get0_certs(const OCSP_BASICRESP *bs);
+#else
+#define q_OCSP_resp_get0_certs(bs) ((bs)->certs)
+#endif
 Q_AUTOTEST_EXPORT OCSP_CERTID *q_OCSP_cert_to_id(const EVP_MD *dgst, X509 *subject, X509 *issuer);
 Q_AUTOTEST_EXPORT void q_OCSP_CERTID_free(OCSP_CERTID *cid);
 int q_OCSP_id_cmp(OCSP_CERTID *a, OCSP_CERTID *b);
