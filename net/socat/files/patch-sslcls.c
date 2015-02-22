--- sslcls.c.orig	2015-01-24 10:15:22 UTC
+++ sslcls.c
@@ -331,6 +331,7 @@ void sycSSL_free(SSL *ssl) {
    return;
 }
 
+#ifdef HAVE_RAND_egd_method
 int sycRAND_egd(const char *path) {
    int result;
    Debug1("RAND_egd(\"%s\")", path);
@@ -338,6 +339,7 @@ int sycRAND_egd(const char *path) {
    Debug1("RAND_egd() -> %d", result);
    return result;
 }
+#endif
 
 DH *sycPEM_read_bio_DHparams(BIO *bp, DH **x, pem_password_cb *cb, void *u) {
    DH *result;
@@ -375,7 +377,7 @@ int sycFIPS_mode_set(int onoff) {
 }
 #endif /* WITH_FIPS */
 
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
 const COMP_METHOD *sycSSL_get_current_compression(SSL *ssl) {
    const COMP_METHOD *result;
    Debug1("SSL_get_current_compression(%p)", ssl);
