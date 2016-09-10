--- lib/ssl.c.orig	2012-06-30 14:30:08 UTC
+++ lib/ssl.c
@@ -78,6 +78,7 @@ static void os_initialize_prng(struct ss
     int totbytes = 0;
     int bytes;
 
+#ifndef OPENSSL_NO_EGD
     if (ssl_config->egd_socket) {
         if ((bytes = RAND_egd(ssl_config->egd_socket)) == -1) {
             log_fatal("EGD Socket %s failed", ssl_config->egd_socket);
@@ -88,6 +89,7 @@ static void os_initialize_prng(struct ss
             goto SEEDED;        /* ditto */
         }
     }
+#endif
 
     /* Try the good-old default /dev/urandom, if available  */
     totbytes += add_rand_file("/dev/urandom");
@@ -387,7 +389,7 @@ void ssl_context_init(struct ssl_config
     SSL_load_error_strings();
 
     /* Set up client context: only used by accountd */
-    client_ctx = SSL_CTX_new(SSLv3_client_method());
+    client_ctx = SSL_CTX_new(SSLv23_client_method());
     SSL_CTX_set_session_cache_mode(client_ctx, SSL_SESS_CACHE_BOTH);
     SSL_CTX_set_info_callback(client_ctx, info_callback);
 #ifdef SSL_MODE_AUTO_RETRY
