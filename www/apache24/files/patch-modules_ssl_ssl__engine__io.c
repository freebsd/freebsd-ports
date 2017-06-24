--- modules/ssl/ssl_engine_io.c.orig	2017-05-30 12:26:05 UTC
+++ modules/ssl/ssl_engine_io.c
@@ -164,7 +164,7 @@ static int bio_filter_create(BIO *bio)
 {
     BIO_set_shutdown(bio, 1);
     BIO_set_init(bio, 1);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     /* No setter method for OpenSSL 1.1.0 available,
      * but I can't find any functional use of the
      * "num" field there either.
@@ -549,7 +549,7 @@ static long bio_filter_in_ctrl(BIO *bio,
     return -1;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
         
 static BIO_METHOD bio_filter_out_method = {
     BIO_TYPE_MEM,
@@ -2024,7 +2024,7 @@ static void ssl_io_input_add_filter(ssl_
 
     filter_ctx->pInputFilter = ap_add_input_filter(ssl_io_filter, inctx, r, c);
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     filter_ctx->pbioRead = BIO_new(&bio_filter_in_method);
 #else
     filter_ctx->pbioRead = BIO_new(bio_filter_in_method);
@@ -2059,7 +2059,7 @@ void ssl_io_filter_init(conn_rec *c, req
     filter_ctx->pOutputFilter   = ap_add_output_filter(ssl_io_filter,
                                                        filter_ctx, r, c);
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     filter_ctx->pbioWrite       = BIO_new(&bio_filter_out_method);
 #else
     filter_ctx->pbioWrite       = BIO_new(bio_filter_out_method);
