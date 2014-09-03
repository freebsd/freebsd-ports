--- src/ssl.c.orig
+++ src/ssl.c
@@ -29,10 +29,7 @@
 
 #include <gnutls/gnutls.h>
 #include <gnutls/x509.h>
-#include <gcrypt.h>
 #ifdef ENABLE_SMP
-GCRY_THREAD_OPTION_PTHREAD_IMPL;
-
 pthread_mutex_t ssl_session_cache_lock = PTHREAD_MUTEX_INITIALIZER;
 #endif
 
@@ -51,12 +48,12 @@
                         */
 
 static void wrap_db_init(void);
-static int wrap_db_store(void *dbf, gnutls_datum key, gnutls_datum data);
-static gnutls_datum wrap_db_fetch(void *dbf, gnutls_datum key);
-static int wrap_db_delete(void *dbf, gnutls_datum key);
+static int wrap_db_store(void *dbf, gnutls_datum_t key, gnutls_datum_t data);
+static gnutls_datum_t wrap_db_fetch(void *dbf, gnutls_datum_t key);
+static int wrap_db_delete(void *dbf, gnutls_datum_t key);
 
 static int cur = 0; /* points to the credentials structure used */
-static gnutls_certificate_credentials credentials[2] = { NULL, NULL };
+static gnutls_certificate_credentials_t credentials[2] = { NULL, NULL };
 
 static int need_dh_params = 0; /* whether we need to generate DHE
  * parameters. Depend on the chosen ciphersuites.
@@ -69,10 +66,10 @@
  */
 extern int ssl_dh_bits;
 
-gnutls_dh_params _dh_params[2];
-gnutls_rsa_params _rsa_params[2];
+gnutls_dh_params_t _dh_params[2];
+gnutls_rsa_params_t _rsa_params[2];
 
-static int generate_dh_primes( gnutls_dh_params* dh_params)
+static int generate_dh_primes( gnutls_dh_params_t* dh_params)
 {
     if (gnutls_dh_params_init( dh_params) < 0) {
         log_error_time();
@@ -101,7 +98,7 @@
      return 0;
 }
 
-static int generate_rsa_params( gnutls_rsa_params* rsa_params)
+static int generate_rsa_params( gnutls_rsa_params_t* rsa_params)
 {
     if (gnutls_rsa_params_init( rsa_params) < 0) {
 	log_error_time();
@@ -165,9 +162,9 @@
 /* Initializes a single SSL/TLS session. That is set the algorithm,
  * the db backend, whether to request certificates etc.
  */
-gnutls_session initialize_ssl_session(void)
+gnutls_session_t initialize_ssl_session(void)
 {
-    gnutls_session state;
+    gnutls_session_t state;
     
     gnutls_init(&state, GNUTLS_SERVER);
 
@@ -215,9 +212,6 @@
 
     log_error_time();
     fprintf(stderr, "tls: Initializing GnuTLS/%s.\n", gnutls_check_version(NULL));
-#ifdef ENABLE_SMP
-    gcry_control (GCRYCTL_SET_THREAD_CBS, &gcry_threads_pthread);
-#endif
     gnutls_global_init();
 
     if (gnutls_certificate_allocate_credentials( &credentials[0]) < 0) {
@@ -294,8 +288,6 @@
     	comp_priority[i++] = GNUTLS_COMP_NULL;
     if ( parse_cs_string( ssl_comp, "ZLIB") != 0)
     	comp_priority[i++] = GNUTLS_COMP_ZLIB;
-    if ( parse_cs_string( ssl_comp, "LZO") != 0)
-    	comp_priority[i++] = GNUTLS_COMP_LZO;
     comp_priority[i] = 0;
 
     /* Add protocols
@@ -416,7 +408,7 @@
     cache_db = calloc(1, ssl_session_cache * sizeof(CACHE));
 }
 
-static int wrap_db_store(void *dbf, gnutls_datum key, gnutls_datum data)
+static int wrap_db_store(void *dbf, gnutls_datum_t key, gnutls_datum_t data)
 {
 
     if (cache_db == NULL)
@@ -447,9 +439,9 @@
     return 0;
 }
 
-static gnutls_datum wrap_db_fetch(void *dbf, gnutls_datum key)
+static gnutls_datum_t wrap_db_fetch(void *dbf, gnutls_datum_t key)
 {
-    gnutls_datum res = { NULL, 0 };
+    gnutls_datum_t res = { NULL, 0 };
     int i;
 
     if (cache_db == NULL)
@@ -489,7 +481,7 @@
     return res;
 }
 
-static int wrap_db_delete(void *dbf, gnutls_datum key)
+static int wrap_db_delete(void *dbf, gnutls_datum_t key)
 {
 int i;
 
@@ -567,11 +559,11 @@
         
         if (ssl_verify >= 1) {
            size_t size;
-           int verify, ret, valid;
+           int ret, valid;
            char name[128];
-           const gnutls_datum *cert_list;
-           int cert_list_size;
-           gnutls_x509_crt crt = NULL;
+           const gnutls_datum_t *cert_list;
+           unsigned int cert_list_size, verify;
+           gnutls_x509_crt_t crt = NULL;
 
            ret = gnutls_x509_crt_init( &crt);
            if (ret < 0) {
@@ -601,7 +593,7 @@
 	   }
 
 
-           verify = gnutls_certificate_verify_peers( current->ssl_state);
+           gnutls_certificate_verify_peers2( current->ssl_state, &verify);
            current->certificate_verified = "NONE";
 
            if (cert_list == NULL) {
@@ -737,8 +729,6 @@
     	comp_priority[i++] = GNUTLS_COMP_NULL;
     if ( parse_cs_string( ssl_comp, "ZLIB") != 0)
     	comp_priority[i++] = GNUTLS_COMP_ZLIB;
-    if ( parse_cs_string( ssl_comp, "LZO") != 0)
-    	comp_priority[i++] = GNUTLS_COMP_LZO;
     comp_priority[i] = 0;
 
     /* Add protocols
