--- sx/ssl.c.orig	2016-05-22 16:19:36 UTC
+++ sx/ssl.c
@@ -70,7 +70,7 @@ static int _sx_ssl_verify_callback(int preverify_ok, X
      */
     if (!preverify_ok && (err == X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT))
     {
-      X509_NAME_oneline(X509_get_issuer_name(ctx->current_cert), buf, 256);
+      X509_NAME_oneline(X509_get_issuer_name(err_cert), buf, 256);
       _sx_debug(ZONE, "issuer= %s\n", buf);
     }
 
@@ -115,12 +115,27 @@ static DH *sx_ssl_make_dh_params(BIGNUM *(*const get_p
     if (!dh)
         return NULL;
 
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
     dh->p = get_prime(NULL);
     BN_dec2bn(&dh->g, gen);
     if (!dh->p || !dh->g) {
         DH_free(dh);
         return NULL;
     }
+#else
+    {
+        BIGNUM *p, *g = NULL;
+        p = get_prime(NULL);
+        BN_dec2bn(&g, gen);
+
+        if (p == NULL || g == NULL || !DH_set0_pqg(dh, p, NULL, g)) {
+            DH_free(dh);
+            BN_free(p);
+            BN_free(g);
+            return NULL;
+        }
+    }
+#endif
     return dh;
 }
 
@@ -134,7 +149,7 @@ static void sx_ssl_free_dh_params(void) {
 
 static DH *_sx_ssl_tmp_dh_callback(SSL *ssl, int export, int keylen) {
     EVP_PKEY *pkey = SSL_get_privatekey(ssl);
-    int type = pkey ? EVP_PKEY_type(pkey->type) : EVP_PKEY_NONE;
+    int type = pkey ? EVP_PKEY_base_id(pkey) : EVP_PKEY_NONE;
     unsigned i;
 
     if (type == EVP_PKEY_RSA || type == EVP_PKEY_DSA)
@@ -351,7 +366,11 @@ static void _sx_ssl_get_external_id(sx_t s, _sx_ssl_co
             } else if (altname->type == GEN_DNS) {
                 len = ASN1_STRING_length(altname->d.dNSName);
                 sc->external_id[id] = (char *) malloc(sizeof(char) *  (len + 1));
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
                 memcpy(sc->external_id[id], ASN1_STRING_data(altname->d.dNSName), len);
+#else
+                memcpy(sc->external_id[id], ASN1_STRING_get0_data(altname->d.dNSName), len);
+#endif
                 sc->external_id[id][len] = '\0'; // just to make sure
                 _sx_debug(ZONE, "external_id: Found(%d) subjectAltName/dNSName: '%s'", id, sc->external_id[id]);
                 id++;
@@ -728,11 +747,15 @@ static void _sx_ssl_client(sx_t s, sx_plugin_t p) {
     SSL_set_bio(sc->ssl, sc->rbio, sc->wbio);
     SSL_set_connect_state(sc->ssl);
     SSL_set_options(sc->ssl, SSL_OP_NO_TICKET);
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
 #ifdef ENABLE_EXPERIMENTAL
     SSL_set_ssl_method(sc->ssl, TLSv1_2_client_method());
 #else
     SSL_set_ssl_method(sc->ssl, TLSv1_client_method());
 #endif
+#else
+    SSL_set_ssl_method(sc->ssl, TLS_client_method());
+#endif
 
     /* empty external_id */
     for (i = 0; i < SX_CONN_EXTERNAL_ID_MAX_COUNT; i++)
@@ -761,8 +784,8 @@ static void _sx_ssl_client(sx_t s, sx_plugin_t p) {
         }
 
         /* set callback giving a password for pemfile */
-        SSL_CTX_set_default_passwd_cb_userdata(sc->ssl->ctx, (void *)pemfile_password);
-        SSL_CTX_set_default_passwd_cb(sc->ssl->ctx, &_sx_pem_passwd_callback);
+        SSL_CTX_set_default_passwd_cb_userdata(ctx, (void *)pemfile_password);
+        SSL_CTX_set_default_passwd_cb(ctx, &_sx_pem_passwd_callback);
 
         /* load the private key */
         ret = SSL_use_PrivateKey_file(sc->ssl, pemfile, SSL_FILETYPE_PEM);
@@ -977,11 +1000,15 @@ int sx_ssl_server_addcert(sx_plugin_t p, const char *n
     ERR_clear_error();
 
     /* create the context */
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
 #ifdef ENABLE_EXPERIMENTAL
     ctx = SSL_CTX_new(TLSv1_2_method());
 #else
     ctx = SSL_CTX_new(SSLv23_method());
 #endif
+#else
+    ctx = SSL_CTX_new(TLS_method());
+#endif
     if(ctx == NULL) {
         _sx_debug(ZONE, "ssl context creation failed; %s", ERR_error_string(ERR_get_error(), NULL));
         return 1;
@@ -1063,7 +1090,11 @@ int sx_ssl_server_addcert(sx_plugin_t p, const char *n
     /* try to read DH params from pem file */
     if((dhparams = sx_ssl_get_DHparams(pemfile))) {
         SSL_CTX_set_tmp_dh(ctx, dhparams);
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
         _sx_debug(ZONE, "custom DH parameters loaded from certificate", BN_num_bits(dhparams->p));
+#else
+        _sx_debug(ZONE, "custom DH parameters loaded from certificate", DH_bits(dhparams));
+#endif
     }
 
     /* try to read ECDH params from pem file */
