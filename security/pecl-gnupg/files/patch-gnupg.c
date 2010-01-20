#
# http://www.freebsd.org/cgi/query-pr.cgi?pr=142311
#
--- gnupg.c.orig	2010-01-04 18:08:52.000000000 +0100
+++ gnupg.c	2010-01-04 18:09:14.000000000 +0100
@@ -136,6 +136,7 @@
 static void gnupg_res_init(gnupg_object *intern TSRMLS_DC){
 	/* init the gpgme-lib and set the default values */
 	gpgme_ctx_t	ctx;
+	gpgme_check_version                             (0);
 	gpgme_new					(&ctx);
 	gpgme_set_armor				(ctx,1);
 	intern->ctx				=	ctx;
