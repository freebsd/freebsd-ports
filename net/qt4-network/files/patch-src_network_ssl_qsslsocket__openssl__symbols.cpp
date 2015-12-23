--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2015-05-07 14:14:44 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -228,13 +228,17 @@ DEFINEFUNC(int, SSL_shutdown, SSL *a, a,
 #ifndef OPENSSL_NO_SSL2
 DEFINEFUNC(const SSL_METHOD *, SSLv2_client_method, DUMMYARG, DUMMYARG, return 0, return)
 #endif
+#ifndef OPENSSL_NO_SSL3
 DEFINEFUNC(const SSL_METHOD *, SSLv3_client_method, DUMMYARG, DUMMYARG, return 0, return)
+#endif
 DEFINEFUNC(const SSL_METHOD *, SSLv23_client_method, DUMMYARG, DUMMYARG, return 0, return)
 DEFINEFUNC(const SSL_METHOD *, TLSv1_client_method, DUMMYARG, DUMMYARG, return 0, return)
 #ifndef OPENSSL_NO_SSL2
 DEFINEFUNC(const SSL_METHOD *, SSLv2_server_method, DUMMYARG, DUMMYARG, return 0, return)
 #endif
+#ifndef OPENSSL_NO_SSL3
 DEFINEFUNC(const SSL_METHOD *, SSLv3_server_method, DUMMYARG, DUMMYARG, return 0, return)
+#endif
 DEFINEFUNC(const SSL_METHOD *, SSLv23_server_method, DUMMYARG, DUMMYARG, return 0, return)
 DEFINEFUNC(const SSL_METHOD *, TLSv1_server_method, DUMMYARG, DUMMYARG, return 0, return)
 #else
@@ -511,9 +511,9 @@ static QPair<QLibrary*, QLibrary*> loadO
     libcrypto->setLoadHints(libcrypto->loadHints() | QLibrary::ImprovedSearchHeuristics);
 #elif defined(SHLIB_VERSION_NUMBER)
     // first attempt: the canonical name is libssl.so.<SHLIB_VERSION_NUMBER>
-    libssl->setFileNameAndVersion(QLatin1String("ssl"), QLatin1String(SHLIB_VERSION_NUMBER));
+    libssl->setFileNameAndVersion(QLatin1String("/usr/local/lib/libssl"), QLatin1String(SHLIB_VERSION_NUMBER));
     libssl->setLoadHints(QLibrary::ImprovedSearchHeuristics);
-    libcrypto->setFileNameAndVersion(QLatin1String("crypto"), QLatin1String(SHLIB_VERSION_NUMBER));
+    libcrypto->setFileNameAndVersion(QLatin1String("/usr/local/lib/libcrypto"), QLatin1String(SHLIB_VERSION_NUMBER));
     libcrypto->setLoadHints(libcrypto->loadHints() | QLibrary::ImprovedSearchHeuristics);
     if (libcrypto->load() && libssl->load()) {
         // libssl.so.<SHLIB_VERSION_NUMBER> and libcrypto.so.<SHLIB_VERSION_NUMBER> found
@@ -525,8 +525,8 @@ static QPair<QLibrary*, QLibrary*> loadO
 #endif
 
     // second attempt: find the development files libssl.so and libcrypto.so
-    libssl->setFileNameAndVersion(QLatin1String("ssl"), -1);
-    libcrypto->setFileNameAndVersion(QLatin1String("crypto"), -1);
+    libssl->setFileNameAndVersion(QLatin1String("/usr/local/lib/libssl"), -1);
+    libcrypto->setFileNameAndVersion(QLatin1String("/usr/local/lib/libcrypto"), -1);
     if (libcrypto->load() && libssl->load()) {
         // libssl.so.0 and libcrypto.so.0 found
         return pair;
@@ -822,13 +826,17 @@ bool q_resolveOpenSslSymbols()
 #ifndef OPENSSL_NO_SSL2
     RESOLVEFUNC(SSLv2_client_method)
 #endif
+#ifndef OPENSSL_NO_SSL3
     RESOLVEFUNC(SSLv3_client_method)
+#endif
     RESOLVEFUNC(SSLv23_client_method)
     RESOLVEFUNC(TLSv1_client_method)
 #ifndef OPENSSL_NO_SSL2
     RESOLVEFUNC(SSLv2_server_method)
 #endif
+#ifndef OPENSSL_NO_SSL3
     RESOLVEFUNC(SSLv3_server_method)
+#endif
     RESOLVEFUNC(SSLv23_server_method)
     RESOLVEFUNC(TLSv1_server_method)
     RESOLVEFUNC(X509_NAME_entry_count)
