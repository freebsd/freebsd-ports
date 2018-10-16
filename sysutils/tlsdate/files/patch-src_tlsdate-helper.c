Obtained from:	https://chromium-review.googlesource.com/c/chromiumos/third_party/tlsdate/+/549533

--- src/tlsdate-helper.c.orig	2015-05-28 18:49:40 UTC
+++ src/tlsdate-helper.c
@@ -370,11 +370,29 @@ xfree (void *ptr)
   free(ptr);
 }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+size_t
+SSL_get_server_random(const SSL *ssl, unsigned char *out, size_t outlen)
+{
+  size_t ret = min(outlen, sizeof(uint32_t));
+  // Per https://www.openssl.org/docs/man1.1.0/ssl/SSL_get_server_random.html
+  // If outlen is 0, return the maximum number of bytes that would be copied.
+  if (!outlen)
+    return sizeof(uint32_t);
+  memcpy(out, ssl->s3->server_random, ret);
+  return ret;
+}
+#endif
+
 void
 openssl_time_callback (const SSL* ssl, int where, int ret)
 {
   if (where == SSL_CB_CONNECT_LOOP &&
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
       (ssl->state == SSL3_ST_CR_SRVR_HELLO_A || ssl->state == SSL3_ST_CR_SRVR_HELLO_B))
+#else
+      (SSL_get_state(ssl) == TLS_ST_CR_SRVR_HELLO))
+#endif
   {
     // XXX TODO: If we want to trust the remote system for time,
     // can we just read that time out of the remote system and if the
@@ -387,7 +405,7 @@ openssl_time_callback (const SSL* ssl, i
     uint32_t max_reasonable_time = MAX_REASONABLE_TIME;
     uint32_t server_time;
     verb("V: freezing time for x509 verification");
-    memcpy(&server_time, ssl->s3->server_random, sizeof(uint32_t));
+    SSL_get_server_random(ssl, (unsigned char *)&server_time, sizeof (uint32_t));
     if (compiled_time < ntohl(server_time)
         &&
         ntohl(server_time) < max_reasonable_time)
@@ -395,7 +413,7 @@ openssl_time_callback (const SSL* ssl, i
       verb("V: remote peer provided: %d, preferred over compile time: %d",
             ntohl(server_time), compiled_time);
       verb("V: freezing time with X509_VERIFY_PARAM_set_time");
-      X509_VERIFY_PARAM_set_time(ssl->ctx->cert_store->param,
+      X509_VERIFY_PARAM_set_time(SSL_get0_param((SSL *)ssl),
                                  (time_t) ntohl(server_time) + 86400);
     } else {
       die("V: the remote server is a false ticker! server: %d compile: %d",
@@ -404,6 +422,12 @@ openssl_time_callback (const SSL* ssl, i
   }
 }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#define EVP_PKEY_BN_bits(p, k) BN_num_bits((p)->pkey.k)
+#else
+#define EVP_PKEY_BN_bits(p, k) EVP_PKEY_bits(p)
+#endif
+
 uint32_t
 get_certificate_keybits (EVP_PKEY *public_key)
 {
@@ -411,39 +435,39 @@ get_certificate_keybits (EVP_PKEY *publi
     In theory, we could use check_bitlen_dsa() and check_bitlen_rsa()
    */
   uint32_t key_bits;
-  switch (public_key->type)
+  switch (EVP_PKEY_id(public_key))
   {
     case EVP_PKEY_RSA:
       verb("V: key type: EVP_PKEY_RSA");
-      key_bits = BN_num_bits(public_key->pkey.rsa->n);
+      key_bits = EVP_PKEY_BN_bits(public_key, rsa->n);
       break;
     case EVP_PKEY_RSA2:
       verb("V: key type: EVP_PKEY_RSA2");
-      key_bits = BN_num_bits(public_key->pkey.rsa->n);
+      key_bits = EVP_PKEY_BN_bits(public_key, rsa->n);
       break;
     case EVP_PKEY_DSA:
       verb("V: key type: EVP_PKEY_DSA");
-      key_bits = BN_num_bits(public_key->pkey.dsa->p);
+      key_bits = EVP_PKEY_BN_bits(public_key, dsa->p);
       break;
     case EVP_PKEY_DSA1:
       verb("V: key type: EVP_PKEY_DSA1");
-      key_bits = BN_num_bits(public_key->pkey.dsa->p);
+      key_bits = EVP_PKEY_BN_bits(public_key, dsa->p);
       break;
     case EVP_PKEY_DSA2:
       verb("V: key type: EVP_PKEY_DSA2");
-      key_bits = BN_num_bits(public_key->pkey.dsa->p);
+      key_bits = EVP_PKEY_BN_bits(public_key, dsa->p);
       break;
     case EVP_PKEY_DSA3:
       verb("V: key type: EVP_PKEY_DSA3");
-      key_bits = BN_num_bits(public_key->pkey.dsa->p);
+      key_bits = EVP_PKEY_BN_bits(public_key, dsa->p);
       break;
     case EVP_PKEY_DSA4:
       verb("V: key type: EVP_PKEY_DSA4");
-      key_bits = BN_num_bits(public_key->pkey.dsa->p);
+      key_bits = EVP_PKEY_BN_bits(public_key, dsa->p);
       break;
     case EVP_PKEY_DH:
       verb("V: key type: EVP_PKEY_DH");
-      key_bits = BN_num_bits(public_key->pkey.dh->pub_key);
+      key_bits = EVP_PKEY_BN_bits(public_key, dh->pub_key);
       break;
     case EVP_PKEY_EC:
       verb("V: key type: EVP_PKEY_EC");
@@ -681,7 +705,9 @@ check_san (SSL *ssl, const char *hostnam
 
         int j;
         void *extvalstr;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
         const unsigned char *tmp;
+#endif
 
         STACK_OF(CONF_VALUE) *val;
         CONF_VALUE *nval;
@@ -695,6 +721,7 @@ check_san (SSL *ssl, const char *hostnam
           break;
         }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
         tmp = ext->value->data;
         if (method->it)
         {
@@ -703,7 +730,9 @@ check_san (SSL *ssl, const char *hostnam
         } else {
           extvalstr = method->d2i(NULL, &tmp, ext->value->length);
         }
-
+#else
+	extvalstr = X509V3_EXT_d2i(ext);
+#endif
         if (!extvalstr)
         {
           break;
@@ -886,11 +915,11 @@ check_key_length (SSL *ssl)
   }
 
   key_bits = get_certificate_keybits (public_key);
-  if (MIN_PUB_KEY_LEN >= key_bits && public_key->type != EVP_PKEY_EC)
+  if (MIN_PUB_KEY_LEN >= key_bits && EVP_PKEY_id(public_key) != EVP_PKEY_EC)
   {
     die ("Unsafe public key size: %d bits", key_bits);
   } else {
-     if (public_key->type == EVP_PKEY_EC)
+     if (EVP_PKEY_id(public_key) == EVP_PKEY_EC)
        if(key_bits >= MIN_ECC_PUB_KEY_LEN
           && key_bits <= MAX_ECC_PUB_KEY_LEN)
        {
@@ -1129,20 +1158,34 @@ run_ssl (uint32_t *time_map, int time_is
   SSL_library_init();
 
   ctx = NULL;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
   if (0 == strcmp("sslv23", protocol))
   {
     verb ("V: using SSLv23_client_method()");
     ctx = SSL_CTX_new(SSLv23_client_method());
+#ifndef OPENSSL_NO_SSL3_METHOD
   } else if (0 == strcmp("sslv3", protocol))
   {
     verb ("V: using SSLv3_client_method()");
     ctx = SSL_CTX_new(SSLv3_client_method());
+#endif
+#ifndef OPENSSL_NO_TLS1_METHOD
   } else if (0 == strcmp("tlsv1", protocol))
   {
     verb ("V: using TLSv1_client_method()");
     ctx = SSL_CTX_new(TLSv1_client_method());
+#endif
   } else
     die("Unsupported protocol `%s'", protocol);
+#else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
+  /*
+   * Use general-purpose version-flexible SSL/TLS method. The actual protocol
+   * version used will be negotiated to the highest version mutually supported
+   * by the client and the server.
+   */
+  verb ("V: using TLS_client_method()\n");
+  ctx = SSL_CTX_new(TLS_client_method());
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
 
   if (ctx == NULL)
     die("OpenSSL failed to support protocol `%s'", protocol);
@@ -1204,7 +1247,7 @@ run_ssl (uint32_t *time_map, int time_is
 
   // from /usr/include/openssl/ssl3.h
   //  ssl->s3->server_random is an unsigned char of 32 bits
-  memcpy(&result_time, ssl->s3->server_random, sizeof (uint32_t));
+  SSL_get_server_random(ssl, (unsigned char *)&result_time, sizeof (uint32_t));
   verb("V: In TLS response, T=%lu", (unsigned long)ntohl(result_time));
 
   if (http) {
