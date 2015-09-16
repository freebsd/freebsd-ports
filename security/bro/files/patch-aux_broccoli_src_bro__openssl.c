$OpenBSD: patch-aux_broccoli_src_bro_openssl_c,v 1.1 2015/07/19 16:38:48 sthen Exp $
--- aux/broccoli/src/bro_openssl.c.orig	2015-01-23 18:49:02 UTC
+++ aux/broccoli/src/bro_openssl.c
@@ -302,7 +302,7 @@ __bro_openssl_init(void)
    * to set up an SSL connection now and abort if this fails in any way.
    */
 
-  if (! (ctx = SSL_CTX_new(SSLv3_method())))
+  if (! (ctx = SSL_CTX_new(SSLv23_method())))
     D_RETURN_(FALSE);
   
   /* We expect things to be stored in PEM format, which means that we
