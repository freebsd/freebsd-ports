--- src/web.c.orig	2006-04-24 08:44:09 UTC
+++ src/web.c
@@ -123,7 +123,11 @@ SSL_CTX *SU_SSL_InitializeCTX(char *pcEr
   char errormsg[1024];
   SSL_CTX *sslctx;
 
+#ifndef OPENSSL_NO_SSL3
   sslctx = SSL_CTX_new(SSLv3_client_method());
+#else
+  sslctx = SSL_CTX_new(SSLv23_client_method());
+#endif
   if(sslctx == NULL)
   {
     ERR_error_string(ERR_get_error(), errormsg);
