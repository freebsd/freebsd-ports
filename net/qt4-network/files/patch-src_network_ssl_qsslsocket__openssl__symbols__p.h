--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2015-05-07 14:14:44 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols_p.h
@@ -218,6 +218,9 @@ void q_CRYPTO_set_locking_callback(void 
 void q_CRYPTO_set_id_callback(unsigned long (*a)());
 void q_CRYPTO_free(void *a);
 void q_DSA_free(DSA *a);
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+int q_DSA_bits(DSA *a);
+#endif
 #if OPENSSL_VERSION_NUMBER >= 0x00908000L
 // 0.9.8 broke SC and BC by changing this function's signature.
 X509 *q_d2i_X509(X509 **a, const unsigned char **b, long c);
@@ -227,12 +230,18 @@ X509 *q_d2i_X509(X509 **a, unsigned char
 char *q_ERR_error_string(unsigned long a, char *b);
 unsigned long q_ERR_get_error();
 const EVP_CIPHER *q_EVP_des_ede3_cbc();
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+const EVP_MD *q_EVP_sha1();
+#endif
 int q_EVP_PKEY_assign(EVP_PKEY *a, int b, char *c);
 int q_EVP_PKEY_set1_RSA(EVP_PKEY *a, RSA *b);
 int q_EVP_PKEY_set1_DSA(EVP_PKEY *a, DSA *b);
 void q_EVP_PKEY_free(EVP_PKEY *a);
 RSA *q_EVP_PKEY_get1_RSA(EVP_PKEY *a);
 DSA *q_EVP_PKEY_get1_DSA(EVP_PKEY *a);
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+int q_EVP_PKEY_base_id(EVP_PKEY *a);
+#endif
 int q_EVP_PKEY_type(int a);
 EVP_PKEY *q_EVP_PKEY_new();
 int q_i2d_X509(X509 *a, unsigned char **b);
@@ -258,6 +267,9 @@ int q_PEM_write_bio_RSA_PUBKEY(BIO *a, R
 void q_RAND_seed(const void *a, int b);
 int q_RAND_status();
 void q_RSA_free(RSA *a);
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+int q_RSA_bits(RSA *a);
+#endif
 int q_sk_num(STACK *a);
 void q_sk_pop_free(STACK *a, void (*b)(void *));
 #if OPENSSL_VERSION_NUMBER >= 0x10000000L
@@ -270,6 +282,9 @@ char * q_sk_value(STACK *a, int b);
 int q_SSL_accept(SSL *a);
 int q_SSL_clear(SSL *a);
 char *q_SSL_CIPHER_description(SSL_CIPHER *a, char *b, int c);
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+int q_SSL_CIPHER_get_bits(SSL_CIPHER *a, int *b);
+#endif
 int q_SSL_connect(SSL *a);
 #if OPENSSL_VERSION_NUMBER >= 0x00908000L
 // 0.9.8 broke SC and BC by changing this function's signature.
@@ -293,6 +308,7 @@ int q_SSL_CTX_use_certificate_file(SSL_C
 int q_SSL_CTX_use_PrivateKey(SSL_CTX *a, EVP_PKEY *b);
 int q_SSL_CTX_use_RSAPrivateKey(SSL_CTX *a, RSA *b);
 int q_SSL_CTX_use_PrivateKey_file(SSL_CTX *a, const char *b, int c);
+X509_STORE *q_SSL_CTX_get_cert_store(const SSL_CTX *a);
 void q_SSL_free(SSL *a);
 #if OPENSSL_VERSION_NUMBER >= 0x00908000L
 // 0.9.8 broke SC and BC by changing this function's signature.
@@ -353,6 +369,9 @@ void *q_ASN1_dup(i2d_of_void *i2d, d2i_o
 #else
 X509 *q_X509_dup(X509 *a);
 #endif
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+int q_X509_digest(const X509 *x509, const EVP_MD *type, unsigned char *md, unsigned int *len);
+#endif
 ASN1_OBJECT *q_X509_EXTENSION_get_object(X509_EXTENSION *a);
 void q_X509_free(X509 *a);
 X509_EXTENSION *q_X509_get_ext(X509 *a, int b);
@@ -360,6 +379,13 @@ int q_X509_get_ext_count(X509 *a);
 void *q_X509_get_ext_d2i(X509 *a, int b, int *c, int *d);
 X509_NAME *q_X509_get_issuer_name(X509 *a);
 X509_NAME *q_X509_get_subject_name(X509 *a);
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+long q_X509_get_version(X509 *a);
+ASN1_INTEGER *q_X509_get_serialNumber(X509 *a);
+EVP_PKEY *q_X509_get_pubkey(X509 *a);
+const ASN1_TIME *q_X509_get0_notBefore(X509 *a);
+const ASN1_TIME *q_X509_get0_notAfter(X509 *a);
+#endif
 int q_X509_verify_cert(X509_STORE_CTX *ctx);
 int q_X509_NAME_entry_count(X509_NAME *a);
 X509_NAME_ENTRY *q_X509_NAME_get_entry(X509_NAME *a,int b);
@@ -399,7 +425,11 @@ DSA *q_d2i_DSAPrivateKey(DSA **a, unsign
 		PEM_ASN1_write_bio((int (*)(void*, unsigned char**))q_i2d_DSAPrivateKey,PEM_STRING_DSA,\
 			bp,(char *)x,enc,kstr,klen,cb,u)
 #endif
+#if OPENSSL_VERSION_NUMBER <= 0x10100000L
 #define q_SSL_CTX_set_options(ctx,op) q_SSL_CTX_ctrl((ctx),SSL_CTRL_OPTIONS,(op),NULL)
+#else
+unsigned long q_SSL_CTX_set_options(SSL_CTX *ctx, unsigned long op);
+#endif
 #define q_SKM_sk_num(type, st) ((int (*)(const STACK_OF(type) *))q_sk_num)(st)
 #define q_SKM_sk_value(type, st,i) ((type * (*)(const STACK_OF(type) *, int))q_sk_value)(st, i)
 #define q_sk_GENERAL_NAME_num(st) q_SKM_sk_num(GENERAL_NAME, (st))
