--- src/ssl.c.orig	2015-09-28 21:50:26 UTC
+++ src/ssl.c
@@ -251,7 +251,12 @@ SslInitializeCTX(SSL_PROPERTIES *psPrope
    *
    *********************************************************************
    */
+  #ifndef OPENSSL_NO_SSL3
   psProperties->psslCTX = SSL_CTX_new(SSLv3_client_method());
+  #else
+  psProperties->psslCTX = SSL_CTX_new(SSLv23_client_method());
+  SSL_CTX_set_options(psProperties->psslCTX, SSL_OP_NO_SSLv3 | SSL_OP_NO_SSLv2);
+  #endif
   if (psProperties->psslCTX == NULL)
   {
     ERR_error_string(ERR_get_error(), acLocalError);
