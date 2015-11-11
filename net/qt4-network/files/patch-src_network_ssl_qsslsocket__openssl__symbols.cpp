--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2015-05-07 14:14:44 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
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
