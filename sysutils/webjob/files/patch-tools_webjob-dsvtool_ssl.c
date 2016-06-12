--- tools/webjob-dsvtool/ssl.c.orig	2015-10-04 14:04:34 UTC
+++ tools/webjob-dsvtool/ssl.c
@@ -241,7 +241,8 @@ SslInitializeCTX(SSL_PROPERTIES *psPrope
    *
    *********************************************************************
    */
-  psProperties->psslCTX = SSL_CTX_new(SSLv3_client_method());
+  psProperties->psslCTX = SSL_CTX_new(SSLv23_client_method());
+  SSL_CTX_set_options(psProperties->psslCTX, SSL_OP_NO_SSL2 );
   if (psProperties->psslCTX == NULL)
   {
     ERR_error_string(ERR_get_error(), acLocalError);
