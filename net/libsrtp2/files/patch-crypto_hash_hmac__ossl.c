--- crypto/hash/hmac_ossl.c.orig	2022-10-17 11:30:42 UTC
+++ crypto/hash/hmac_ossl.c
@@ -80,7 +80,7 @@ static srtp_err_status_t srtp_hmac_alloc(srtp_auth_t *
 
 /* OpenSSL 1.1.0 made HMAC_CTX an opaque structure, which must be allocated
    using HMAC_CTX_new.  But this function doesn't exist in OpenSSL 1.0.x. */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || LIBRESSL_VERSION_NUMBER
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     {
         /* allocate memory for auth and HMAC_CTX structures */
         uint8_t *pointer;
@@ -126,7 +126,7 @@ static srtp_err_status_t srtp_hmac_dealloc(srtp_auth_t
 
     hmac_ctx = (HMAC_CTX *)a->state;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || LIBRESSL_VERSION_NUMBER
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     HMAC_CTX_cleanup(hmac_ctx);
 
     /* zeroize entire state*/
