--- lib/the_Foundation/src/tlsrequest.c.orig	2023-08-07 17:23:22 UTC
+++ lib/the_Foundation/src/tlsrequest.c
@@ -72,9 +72,9 @@ static iBool readAllFromBIO_(BIO *bio, iBlock *out) {
 /*----------------------------------------------------------------------------------------------*/
 
 iDeclareClass(CachedSession)
-    
+
 static const int maxSessionAge_CachedSession_ = 10 * 60; /* seconds */
-    
+
 struct Impl_CachedSession {
     iObject          object;
     iBlock           pemSession;
@@ -249,7 +249,9 @@ void init_Context(iContext *d) {
     SSL_load_error_strings();
     ERR_load_crypto_strings();
 #endif
+#if OPENSSL_VERSION_NUMBER < 0x30000000L
     ERR_load_BIO_strings();
+#endif
     d->ctx = SSL_CTX_new(TLS_client_method());
     if (!d->ctx) {
         iDebug("[TlsRequest] failed to initialize OpenSSL\n");
@@ -1012,7 +1014,7 @@ static iBool readIncoming_TlsRequest_(iTlsRequest *d) 
 
 static iThreadResult run_TlsRequest_(iThread *thread) {
     iTlsRequest *d = userData_Thread(thread);
-    /* Thread-local pointer to the current request so it can be accessed in the 
+    /* Thread-local pointer to the current request so it can be accessed in the
        verify callback. */
     iDebug("[TlsRequest] run_TlsRequest_: %zu bytes to send\n", size_Block(&d->sending));
     setCurrentRequestForThread_Context_(context_, d);
