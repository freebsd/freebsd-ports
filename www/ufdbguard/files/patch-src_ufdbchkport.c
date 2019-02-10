--- src/ufdbchkport.c.orig	2019-02-08 07:02:37 UTC
+++ src/ufdbchkport.c
@@ -84,7 +84,7 @@ static volatile int tls_inited = 0;
 static pthread_mutex_t init_mutex = UFDB_STATIC_MUTEX_INIT;
 static SSL_CTX * ssl_ctx = NULL;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined LIBRESSL_VERSION_NUMBER
 static int num_static_ssl_locks = 0;
 static pthread_mutex_t * crypto_mutexes = NULL;
 #endif
@@ -895,7 +895,7 @@ void UFDBsetTunnelCheckMethod( int method )
 }
 
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined LIBRESSL_VERSION_NUMBER
 static void ufdb_pthread_locking_callback( 
    int          mode, 
    int          type, 
@@ -945,7 +945,7 @@ static void ufdb_pthread_locking_callback( 
 #endif
 
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined LIBRESSL_VERSION_NUMBER
 static unsigned long ufdb_pthread_id_callback( void )
 {
    unsigned long id = (unsigned long) pthread_self();
@@ -955,7 +955,7 @@ static unsigned long ufdb_pthread_id_callback( void )
 #endif
 
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined LIBRESSL_VERSION_NUMBER
 
 typedef struct CRYPTO_dynlock_value {
    pthread_mutex_t lock;
@@ -1245,7 +1245,7 @@ int UFDBinitHTTPSchecker( void )
       ENGINE_load_builtin_engines();
       CONF_modules_load( NULL, NULL, 0 );
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined LIBRESSL_VERSION_NUMBER
       {
          int    i;
          CRYPTO_set_id_callback( ufdb_pthread_id_callback );	
@@ -2444,7 +2444,7 @@ GCC_NO_INLINE int UFDBopenssl_connect( 
    saved_errno = errno;
    state = SSL_get_state( *ssl );
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined LIBRESSL_VERSION_NUMBER
    if (ret > 0  &&  state == SSL_ST_OK)
 #else
    if (ret > 0  &&  state == TLS_ST_OK)
