--- src/nrpe-ssl.c.orig	2024-12-23 03:34:53 UTC
+++ src/nrpe-ssl.c
@@ -33,7 +33,7 @@ void ssl_set_protocol_version(SslVer ssl_proto_ver, un
 
 void ssl_set_protocol_version(SslVer ssl_proto_ver, unsigned long *ssl_opts)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000
+#if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
 
 	SSL_CTX_set_max_proto_version(ctx, 0);
 
@@ -126,7 +126,7 @@ void ssl_log_startup(int server)
     if (server)
     {
         logit(LOG_INFO, "SSL Client Certs: %s",
-            sslprm.client_certs == 0 ? "Don't Ask" : 
+            sslprm.client_certs == 0 ? "Don't Ask" :
                 (sslprm.client_certs == 1 ? "Accept" : "Require"));
     }
 	logit(LOG_INFO, "SSL Log Options: 0x%02x", sslprm.log_opts);
