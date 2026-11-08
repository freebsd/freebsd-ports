--- tls/openssl/gtlsconnection-openssl.c.orig	2026-09-10 21:18:59 UTC
+++ tls/openssl/gtlsconnection-openssl.c
@@ -160,6 +160,7 @@ end_openssl_io (GTlsConnectionOpenssl  *openssl,
         }
     }
 
+#ifdef SSL_R_SHUTDOWN_WHILE_IN_INIT
   /* XXX: this error happens on ubuntu when shutting down the connection, it
    * seems to be a bug in a specific version of openssl, so let's handle it
    * gracefully
@@ -169,6 +170,7 @@ end_openssl_io (GTlsConnectionOpenssl  *openssl,
       status = G_TLS_CONNECTION_BASE_OK;
       goto out;
     }
+#endif
 
   if (reason == SSL_R_PEER_DID_NOT_RETURN_A_CERTIFICATE || reason == SSL_R_TLSV13_ALERT_CERTIFICATE_REQUIRED)
     {
