--- src/sslcontext.c.orig	2016-04-18 09:49:28 UTC
+++ src/sslcontext.c
@@ -139,7 +139,7 @@ TCN_IMPLEMENT_CALL(jlong, SSLContext, ma
     tcn_ssl_ctxt_t *c = NULL;
     SSL_CTX *ctx = NULL;
     jclass clazz;
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     jint prot;
 #endif
 
@@ -224,7 +224,7 @@ TCN_IMPLEMENT_CALL(jlong, SSLContext, ma
         BIO_set_fp(c->bio_os, stderr, BIO_NOCLOSE | BIO_FP_TEXT);
     SSL_CTX_set_options(c->ctx, SSL_OP_ALL);
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     /* always disable SSLv2, as per RFC 6176 */
     SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2);
     if (!(protocol & SSL_PROTOCOL_SSLV3))
@@ -240,7 +240,7 @@ TCN_IMPLEMENT_CALL(jlong, SSLContext, ma
         SSL_CTX_set_options(c->ctx, SSL_OP_NO_TLSv1_2);
 #endif
 
-#else /* if OPENSSL_VERSION_NUMBER < 0x10100000L */
+#else /* if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER) */
     /* We first determine the maximum protocol version we should provide */
     if (protocol & SSL_PROTOCOL_TLSV1_2) {
         prot = TLS1_2_VERSION;
@@ -269,7 +269,7 @@ TCN_IMPLEMENT_CALL(jlong, SSLContext, ma
         prot = SSL3_VERSION;
     }
     SSL_CTX_set_min_proto_version(ctx, prot);
-#endif /* if OPENSSL_VERSION_NUMBER < 0x10100000L */
+#endif /* if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER) */
 
     /*
      * Configure additional context ingredients
@@ -1577,7 +1577,7 @@ TCN_IMPLEMENT_CALL(void, SSLContext, set
 }
 
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 /*
  * Adapted from OpenSSL:
@@ -1677,7 +1677,7 @@ static const char* SSL_CIPHER_authentica
     if (cipher == NULL) {
         return "UNKNOWN";
     }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     kx = cipher->algorithm_mkey;
     auth = cipher->algorithm_auth;
 #else
@@ -1689,7 +1689,7 @@ static const char* SSL_CIPHER_authentica
         {
     case TCN_SSL_kRSA:
         return SSL_TXT_RSA;
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     case TCN_SSL_kDHr:
         return SSL_TXT_DH "_" SSL_TXT_RSA;
     case TCN_SSL_kDHd:
@@ -1707,7 +1707,7 @@ static const char* SSL_CIPHER_authentica
         default:
             return "UNKNOWN";
             }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     case TCN_SSL_kKRB5:
         return SSL_TXT_KRB5;
     case TCN_SSL_kECDHr:
@@ -1733,7 +1733,7 @@ static const char* SSL_CIPHER_authentica
 }
 
 static const char* SSL_authentication_method(const SSL* ssl) {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
    return SSL_CIPHER_authentication_method(ssl->s3->tmp.new_cipher);
 #else
     /* XXX ssl->s3->tmp.new_cipher is no longer available in OpenSSL 1.1.0 */
