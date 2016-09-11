--- aux/broccoli/src/bro_openssl.c.orig	2015-09-06 19:43:23 UTC
+++ aux/broccoli/src/bro_openssl.c
@@ -302,7 +302,11 @@ __bro_openssl_init(void)
    * to set up an SSL connection now and abort if this fails in any way.
    */
 
+#ifndef OPENSSL_NO_SSL3
   if (! (ctx = SSL_CTX_new(SSLv3_method())))
+#else
+  if (! (ctx = SSL_CTX_new(SSLv23_method())))
+#endif
     D_RETURN_(FALSE);
   
   /* We expect things to be stored in PEM format, which means that we
