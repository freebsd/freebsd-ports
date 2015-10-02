--- src/ssl.c.orig	2014-07-18 08:40:44.000000000 +0200
+++ src/ssl.c	2015-10-02 16:19:04.817153939 +0200
@@ -251,7 +251,16 @@ SslInitializeCTX(SSL_PROPERTIES *psPrope
    *
    *********************************************************************
    */
+#ifndef OPENSSL_NO_SSL3
   psProperties->psslCTX = SSL_CTX_new(SSLv3_client_method());
+#else
+  psProperties->psslCTX = SSL_CTX_new(SSLv23_client_method());
+  SSL_CTX_set_options(psProperties->psslCTX, SSL_OP_NO_SSLv2 | SSL_OP_NO_TLSv1
+#ifdef SSL_OP_NO_TLSv1_2
+  | SSL_OP_NO_TLSv1_1 | SSL_OP_NO_TLSv1_2
+#endif
+  );
+#endif
   if (psProperties->psslCTX == NULL)
   {
     ERR_error_string(ERR_get_error(), acLocalError);
