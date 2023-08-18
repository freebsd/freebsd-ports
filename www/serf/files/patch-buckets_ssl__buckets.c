--- buckets/ssl_buckets.c.orig	2016-06-30 15:45:07 UTC
+++ buckets/ssl_buckets.c
@@ -407,7 +407,7 @@ static int bio_bucket_destroy(BIO *bio)
 
 static long bio_bucket_ctrl(BIO *bio, int cmd, long num, void *ptr)
 {
-    long ret = 1;
+    long ret = 0;
 
     switch (cmd) {
     default:
@@ -415,6 +415,7 @@ static long bio_bucket_ctrl(BIO *bio, int cmd, long nu
         break;
     case BIO_CTRL_FLUSH:
         /* At this point we can't force a flush. */
+        ret = 1;
         break;
     case BIO_CTRL_PUSH:
     case BIO_CTRL_POP:
@@ -555,7 +556,7 @@ get_subject_alt_names(apr_array_header_t **san_arr, X5
         }
         sk_GENERAL_NAME_pop_free(names, GENERAL_NAME_free);
     }
-    
+
     return APR_SUCCESS;
 }
 
@@ -606,7 +607,7 @@ validate_server_certificate(int cert_valid, X509_STORE
         err = X509_STORE_CTX_get_error(store_ctx);
 
         switch(err) {
-            case X509_V_ERR_CERT_NOT_YET_VALID: 
+            case X509_V_ERR_CERT_NOT_YET_VALID:
                     failures |= SERF_SSL_CERT_NOTYETVALID;
                     break;
             case X509_V_ERR_CERT_HAS_EXPIRED:
@@ -741,7 +742,7 @@ validate_server_certificate(int cert_valid, X509_STORE
     {
         ctx->pending_err = SERF_ERROR_SSL_CERT_FAILED;
     }
-        
+
     return cert_valid;
 }
 
@@ -832,7 +833,7 @@ static apr_status_t ssl_decrypt(void *baton, apr_size_
                 necessary mean the connection is closed, let's close
                 it here anyway.
                 We can optimize this later. */
-                serf__log(SSL_VERBOSE, __FILE__, 
+                serf__log(SSL_VERBOSE, __FILE__,
                           "ssl_decrypt: SSL read error: server"
                           " shut down connection!\n");
                 status = APR_EOF;
@@ -842,14 +843,14 @@ static apr_status_t ssl_decrypt(void *baton, apr_size_
             }
         } else {
             *len = ssl_len;
-            serf__log(SSL_MSG_VERBOSE, __FILE__, 
+            serf__log(SSL_MSG_VERBOSE, __FILE__,
                       "---\n%.*s\n-(%d)-\n", *len, buf, *len);
         }
     }
     else {
         *len = 0;
     }
-    serf__log(SSL_VERBOSE, __FILE__, 
+    serf__log(SSL_VERBOSE, __FILE__,
               "ssl_decrypt: %d %d %d\n", status, *len,
               BIO_get_retry_flags(ctx->bio));
 
@@ -956,7 +957,7 @@ static apr_status_t ssl_encrypt(void *baton, apr_size_
 
                 ssl_len = SSL_write(ctx->ssl, vecs_data, interim_len);
 
-                serf__log(SSL_VERBOSE, __FILE__, 
+                serf__log(SSL_VERBOSE, __FILE__,
                           "ssl_encrypt: SSL write: %d\n", ssl_len);
 
                 /* If we failed to write... */
@@ -975,7 +976,7 @@ static apr_status_t ssl_encrypt(void *baton, apr_size_
 
                     ssl_err = SSL_get_error(ctx->ssl, ssl_len);
 
-                    serf__log(SSL_VERBOSE, __FILE__, 
+                    serf__log(SSL_VERBOSE, __FILE__,
                               "ssl_encrypt: SSL write error: %d\n", ssl_err);
 
                     if (ssl_err == SSL_ERROR_SYSCALL) {
@@ -997,7 +998,7 @@ static apr_status_t ssl_encrypt(void *baton, apr_size_
                         }
                     }
 
-                    serf__log(SSL_VERBOSE, __FILE__, 
+                    serf__log(SSL_VERBOSE, __FILE__,
                               "ssl_encrypt: SSL write error: %d %d\n",
                               status, *len);
                 } else {
@@ -1156,7 +1157,7 @@ static void init_ssl_libraries(void)
         }
 #endif
 
-#ifdef USE_OPENSSL_1_1_API
+#if defined(USE_OPENSSL_1_1_API) && !defined(LIBRESSL_VERSION_NUMBER)
         OPENSSL_malloc_init();
 #else
         CRYPTO_malloc_init();
@@ -1196,10 +1197,10 @@ static void init_ssl_libraries(void)
            thread has completed */
         while (val != INIT_DONE) {
             apr_sleep(APR_USEC_PER_SEC / 1000);
-      
+
             val = apr_atomic_cas32(&have_init_ssl,
                                    INIT_UNINITIALIZED,
-                                   INIT_UNINITIALIZED);            
+                                   INIT_UNINITIALIZED);
         }
     }
 }
@@ -1325,9 +1326,14 @@ static int ssl_need_client_cert(SSL *ssl, X509 **cert,
                 return 0;
             }
             else {
+#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x30000000L
                 printf("OpenSSL cert error: %d %d %d\n", ERR_GET_LIB(err),
                        ERR_GET_FUNC(err),
                        ERR_GET_REASON(err));
+#else
+                printf("OpenSSL cert error: %d %d\n", ERR_GET_LIB(err),
+                       ERR_GET_REASON(err));
+#endif
                 PKCS12_free(p12);
                 bio_meth_free(biom);
             }
@@ -1850,7 +1856,7 @@ const char *serf_ssl_cert_export(
 
     encoded_cert = apr_palloc(pool, apr_base64_encode_len(len));
     apr_base64_encode(encoded_cert, binary_cert, len);
-    
+
     return encoded_cert;
 }
 
