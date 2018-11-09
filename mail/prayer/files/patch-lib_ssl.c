--- lib/ssl.c.orig	2012-06-30 14:30:08 UTC
+++ lib/ssl.c
@@ -14,6 +14,7 @@
 /* Headers files for OpenSSL */
 
 #include <openssl/lhash.h>
+#include <openssl/opensslv.h>
 #include <openssl/ssl.h>
 #include <openssl/err.h>
 #include <openssl/rand.h>
@@ -78,17 +79,6 @@ static void os_initialize_prng(struct ssl_config *ssl_
     int totbytes = 0;
     int bytes;
 
-    if (ssl_config->egd_socket) {
-        if ((bytes = RAND_egd(ssl_config->egd_socket)) == -1) {
-            log_fatal("EGD Socket %s failed", ssl_config->egd_socket);
-        } else {
-            totbytes += bytes;
-            log_debug("Snagged %d random bytes from EGD Socket %s",
-                      bytes, ssl_config->egd_socket);
-            goto SEEDED;        /* ditto */
-        }
-    }
-
     /* Try the good-old default /dev/urandom, if available  */
     totbytes += add_rand_file("/dev/urandom");
     if (prng_seeded(totbytes)) {
@@ -212,6 +202,8 @@ static int new_session_cb(SSL * ssl, SSL_SESSION * ses
     unsigned char *data = NULL, *asn;
     time_t expire;
     int ret = -1;
+    unsigned int session_id_length;
+    unsigned char *session_id = SSL_SESSION_get_id(sess, &session_id_length);
 
     if (!sess_dbopen)
         return 0;
@@ -241,8 +233,7 @@ static int new_session_cb(SSL * ssl, SSL_SESSION * ses
     if (data && len) {
         /* store the session in our database */
         do {
-            ret = DB->store(sessdb, (void *) sess->session_id,
-                            sess->session_id_length,
+            ret = DB->store(sessdb, (void *) session_id, session_id_length,
                             (void *) data, len + sizeof(time_t), NULL);
         }
         while (ret == MYDB_AGAIN);
@@ -255,8 +246,8 @@ static int new_session_cb(SSL * ssl, SSL_SESSION * ses
     if (ssl_verbose_logging) {
         int i;
         char idstr[SSL_MAX_SSL_SESSION_ID_LENGTH * 2 + 1];
-        for (i = 0; i < sess->session_id_length; i++)
-            sprintf(idstr + i * 2, "%02X", sess->session_id[i]);
+        for (i = 0; i < session_id_length; i++)
+            sprintf(idstr + i * 2, "%02X", session_id[i]);
 
         log_debug("new SSL session: id=%s, expire=%s, status=%s",
                   idstr, ctime(&expire), ret ? "failed" : "ok");
@@ -298,7 +289,10 @@ static void remove_session(unsigned char *id, int idle
  */
 static void remove_session_cb(SSL_CTX * ctx, SSL_SESSION * sess)
 {
-    remove_session(sess->session_id, sess->session_id_length);
+    unsigned int session_id_length;
+    unsigned char *session_id = SSL_SESSION_get_id(sess, &session_id_length);
+
+    remove_session(session_id, session_id_length);
 }
 
 /*
@@ -387,16 +381,17 @@ void ssl_context_init(struct ssl_config *ssl_config)
     SSL_load_error_strings();
 
     /* Set up client context: only used by accountd */
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     client_ctx = SSL_CTX_new(SSLv3_client_method());
+#else
+    client_ctx = SSL_CTX_new(TLS_client_method());
+#endif
     SSL_CTX_set_session_cache_mode(client_ctx, SSL_SESS_CACHE_BOTH);
     SSL_CTX_set_info_callback(client_ctx, info_callback);
 #ifdef SSL_MODE_AUTO_RETRY
     SSL_CTX_set_mode(client_ctx, SSL_MODE_AUTO_RETRY);
 #endif
 
-    if (SSL_CTX_need_tmp_RSA(client_ctx))
-        SSL_CTX_set_tmp_rsa_callback(client_ctx, rsa_callback);
-
     /* Don't bother with session cache for client side: not enough
      * connections to worry about caching */
     SSL_CTX_set_session_cache_mode(client_ctx, SSL_SESS_CACHE_OFF);
@@ -503,10 +498,6 @@ void ssl_context_init(struct ssl_config *ssl_config)
         log_fatal("SSL_CTX_set_options(SSL_OP_CIPHER_SERVER_PREFERENCE)"
                   "failed");
 
-    /* Set up RSA temporary key callback routine */
-    if (SSL_CTX_need_tmp_RSA(server_ctx))
-        SSL_CTX_set_tmp_rsa_callback(server_ctx, rsa_callback);
-
     /* Initialise RSA temporary key (will take a couple of secs to complete) */
     ssl_init_rsakey(ssl_config);
 }
@@ -615,7 +606,7 @@ void *ssl_start_server(int fd, unsigned long timeout)
     else
         log_debug("SSL: No client certificate");
 
-    switch (ssl->session->ssl_version) {
+    switch (SSL_version(ssl)) {
     case SSL2_VERSION:
         ver = "SSLv2";
         break;
@@ -668,7 +659,7 @@ void *ssl_start_client(int fd, unsigned long timeout)
 
     /* Verify certificate here? Need local context to play with? */
 
-    switch (((SSL *) ssl)->session->ssl_version) {
+    switch (SSL_version(ssl)) {
     case SSL2_VERSION:
         ver = "SSLv2";
         break;
