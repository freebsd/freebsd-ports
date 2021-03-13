--- modules/ssl/ssl_engine_io.c.orig	2020-02-20 16:33:40.000000000 -0800
+++ modules/ssl/ssl_engine_io.c	2021-02-25 16:08:04.863228000 -0800
@@ -242,7 +242,7 @@ static int bio_filter_out_write(BIO *bio, const char *
 
 static long bio_filter_out_ctrl(BIO *bio, int cmd, long num, void *ptr)
 {
-    long ret = 1;
+    long ret = 0;
     bio_filter_out_ctx_t *outctx = (bio_filter_out_ctx_t *)BIO_get_data(bio);
 
     switch (cmd) {
@@ -542,7 +542,7 @@ static int bio_filter_in_gets(BIO *bio, char *buf, int
 
 static long bio_filter_in_ctrl(BIO *bio, int cmd, long num, void *ptr)
 {
-    return -1;
+    return 0;
 }
 
 #if MODSSL_USE_OPENSSL_PRE_1_1_API
@@ -567,7 +567,7 @@ static BIO_METHOD bio_filter_in_method = {
     bio_filter_in_read,
     bio_filter_in_puts,         /* puts is never called */
     bio_filter_in_gets,         /* gets is never called */
-    bio_filter_in_ctrl,         /* ctrl is never called */
+    bio_filter_in_ctrl, 
     bio_filter_create,
     bio_filter_destroy,
     NULL
@@ -594,7 +594,7 @@ void init_bio_methods(void)
     BIO_meth_set_read(bio_filter_in_method, &bio_filter_in_read);
     BIO_meth_set_puts(bio_filter_in_method, &bio_filter_in_puts);   /* puts is never called */
     BIO_meth_set_gets(bio_filter_in_method, &bio_filter_in_gets);   /* gets is never called */
-    BIO_meth_set_ctrl(bio_filter_in_method, &bio_filter_in_ctrl);   /* ctrl is never called */
+    BIO_meth_set_ctrl(bio_filter_in_method, &bio_filter_in_ctrl);
     BIO_meth_set_create(bio_filter_in_method, &bio_filter_create);
     BIO_meth_set_destroy(bio_filter_in_method, &bio_filter_destroy);
 }
