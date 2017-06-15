--- SSLeay.xs.orig	2014-04-23 22:36:24 UTC
+++ SSLeay.xs
@@ -148,16 +148,21 @@ SSL_CTX_new(packname, ssl_version)
         if(ssl_version == 23) {
             ctx = SSL_CTX_new(SSLv23_client_method());
         }
+#ifndef OPENSSL_NO_SSL3
         else if(ssl_version == 3) {
             ctx = SSL_CTX_new(SSLv3_client_method());
         }
+#endif
         else {
 #ifndef OPENSSL_NO_SSL2
             /* v2 is the default */
             ctx = SSL_CTX_new(SSLv2_client_method());
-#else
+#elif !defined(OPENSSL_NO_SSL3)
             /* v3 is the default */
             ctx = SSL_CTX_new(SSLv3_client_method());
+#else
+            /* v23 is the default */
+            ctx = SSL_CTX_new(SSLv23_client_method());
 #endif
         }
 
