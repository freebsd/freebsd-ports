--- src/ssl/support.cc.orig	2017-02-12 21:14:36 UTC
+++ src/ssl/support.cc
@@ -235,7 +235,7 @@ bool Ssl::checkX509ServerValidity(X509 *
     return matchX509CommonNames(cert, (void *)server, check_domain);
 }
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
 static inline X509 *X509_STORE_CTX_get0_cert(X509_STORE_CTX *ctx)
 {
     return ctx->cert;
@@ -379,7 +379,7 @@ ssl_verify_cb(int ok, X509_STORE_CTX * c
 }
 
 // "dup" function for SSL_get_ex_new_index("cert_err_check")
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
 static int
 ssl_dupAclChecklist(CRYPTO_EX_DATA *, const CRYPTO_EX_DATA *, void *,
                     int, long, void *)
@@ -1116,7 +1116,7 @@ hasAuthorityInfoAccessCaIssuers(X509 *ce
             if (ad->location->type == GEN_URI) {
                 xstrncpy(uri,
                          reinterpret_cast<const char *>(
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
                              ASN1_STRING_data(ad->location->d.uniformResourceIdentifier)
 #else
                              ASN1_STRING_get0_data(ad->location->d.uniformResourceIdentifier)
@@ -1291,7 +1291,7 @@ untrustedToStoreCtx_cb(X509_STORE_CTX *c
     // OpenSSL already maintains ctx->untrusted but we cannot modify
     // internal OpenSSL list directly. We have to give OpenSSL our own
     // list, but it must include certificates on the OpenSSL ctx->untrusted
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
     STACK_OF(X509) *oldUntrusted = ctx->untrusted;
 #else
     STACK_OF(X509) *oldUntrusted = X509_STORE_CTX_get0_untrusted(ctx);
@@ -1310,7 +1310,7 @@ untrustedToStoreCtx_cb(X509_STORE_CTX *c
 
     X509_STORE_CTX_set_chain(ctx, sk); // No locking/unlocking, just sets ctx->untrusted
     int ret = X509_verify_cert(ctx);
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
     X509_STORE_CTX_set_chain(ctx, oldUntrusted); // Set back the old untrusted list
 #else
     X509_STORE_CTX_set0_untrusted(ctx, oldUntrusted);
@@ -1535,7 +1535,7 @@ remove_session_cb(SSL_CTX *, SSL_SESSION
 }
 
 static SSL_SESSION *
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
 get_session_cb(SSL *, unsigned char *sessionID, int len, int *copy)
 #else
 get_session_cb(SSL *, const unsigned char *sessionID, int len, int *copy)
