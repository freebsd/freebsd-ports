--- libavformat/tls_openssl.c.orig	2016-10-27 16:17:40 UTC
+++ libavformat/tls_openssl.c
@@ -43,7 +43,7 @@ typedef struct TLSContext {
     TLSShared tls_shared;
     SSL_CTX *ctx;
     SSL *ssl;
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL && !defined(LIBRESSL_VERSION_NUMBER)
     BIO_METHOD* url_bio_method;
 #endif
 } TLSContext;
@@ -68,7 +68,7 @@ static unsigned long openssl_thread_id(v
 
 static int url_bio_create(BIO *b)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL && !defined(LIBRESSL_VERSION_NUMBER)
     BIO_set_init(b, 1);
     BIO_set_data(b, NULL);
     BIO_set_flags(b, 0);
@@ -85,7 +85,7 @@ static int url_bio_destroy(BIO *b)
     return 1;
 }
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL && !defined(LIBRESSL_VERSION_NUMBER)
 #define GET_BIO_DATA(x) BIO_get_data(x);
 #else
 #define GET_BIO_DATA(x) (x)->ptr;
@@ -133,7 +133,7 @@ static int url_bio_bputs(BIO *b, const c
     return url_bio_bwrite(b, str, strlen(str));
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x1010000fL
+#if OPENSSL_VERSION_NUMBER < 0x1010000fL || defined(LIBRESSL_VERSION_NUMBER)
 static BIO_METHOD url_bio_method = {
     .type = BIO_TYPE_SOURCE_SINK,
     .name = "urlprotocol bio",
@@ -212,7 +212,7 @@ static int tls_close(URLContext *h)
         SSL_CTX_free(c->ctx);
     if (c->tls_shared.tcp)
         ffurl_close(c->tls_shared.tcp);
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL && !defined(LIBRESSL_VERSION_NUMBER)
     if (c->url_bio_method)
         BIO_meth_free(c->url_bio_method);
 #endif
@@ -265,7 +265,7 @@ static int tls_open(URLContext *h, const
         ret = AVERROR(EIO);
         goto fail;
     }
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL && !defined(LIBRESSL_VERSION_NUMBER)
     p->url_bio_method = BIO_meth_new(BIO_TYPE_SOURCE_SINK, "urlprotocol bio");
     BIO_meth_set_write(p->url_bio_method, url_bio_bwrite);
     BIO_meth_set_read(p->url_bio_method, url_bio_bread);
