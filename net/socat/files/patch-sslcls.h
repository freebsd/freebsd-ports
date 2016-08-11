--- sslcls.h.orig	2015-01-24 10:15:22 UTC
+++ sslcls.h
@@ -55,7 +55,7 @@ BIO *sycBIO_new_file(const char *filenam
 
 int sycFIPS_mode_set(int onoff);
 
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
 const COMP_METHOD *sycSSL_get_current_compression(SSL *ssl);
 const COMP_METHOD *sycSSL_get_current_expansion(SSL *ssl);
 const char *sycSSL_COMP_get_name(const COMP_METHOD *comp);
