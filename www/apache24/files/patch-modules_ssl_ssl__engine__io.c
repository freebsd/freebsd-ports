--- modules/ssl/ssl_engine_io.c.orig	2020-02-20 16:33:40.000000000 -0800
+++ modules/ssl/ssl_engine_io.c	2021-02-25 16:08:04.863228000 -0800
@@ -242,7 +242,7 @@ static int bio_filter_out_write(BIO *bio, const char *
 
 static long bio_filter_out_ctrl(BIO *bio, int cmd, long num, void *ptr)
 {
-    long ret = 1;
+    long ret = 0;
     bio_filter_out_ctx_t *outctx = (bio_filter_out_ctx_t *)BIO_get_data(bio);
 
     switch (cmd) {
