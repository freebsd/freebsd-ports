--- src/medusa-net.c.orig	2015-09-29 09:03:46 UTC
+++ src/medusa-net.c
@@ -322,12 +322,16 @@ int medusaConnectSSLInternal(sConnectPar
     sslContext = SSL_CTX_new(SSLv2_client_method());
   else
 #endif
+#ifndef OPENSSL_NO_SSL3
   if (pParams->nSSLVersion == 3)
     sslContext = SSL_CTX_new(SSLv3_client_method());
-  else if (pParams->nSSLVersion == (float)3.1)
+  else
+#endif
+  if (pParams->nSSLVersion == (float)3.1)
     sslContext = SSL_CTX_new(TLSv1_client_method());
   else
     sslContext = SSL_CTX_new(SSLv23_client_method());
+    SSL_CTX_set_options(sslContext, SSL_OP_NO_SSLv3 | SSL_OP_NO_SSLv2);
 
   if (sslContext == NULL)
   {
