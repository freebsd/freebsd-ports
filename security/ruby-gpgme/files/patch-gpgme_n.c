--- ./gpgme_n.c.orig	2009-09-16 00:00:05.000000000 -0400
+++ ./gpgme_n.c	2010-10-13 08:09:19.000000000 -0400
@@ -411,6 +411,8 @@
 static VALUE
 rb_s_gpgme_new (VALUE dummy, VALUE rctx)
 {
+  gpgme_check_version(NULL);
+
   gpgme_ctx_t ctx;
   gpgme_error_t err = gpgme_new (&ctx);
 
