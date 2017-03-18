* Boilerplate for SSL_CTX_set1_groups() used in qsslcontext_openssl.cpp
*
* Prepend the path of the SSL libraries used for building so the same libraries are
* found and loaded at runtime. Normal search finds base SSL libraries before ports.
*
--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2016-12-01 08:17:04 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -430,6 +430,7 @@ DEFINEFUNC(void, EC_KEY_free, EC_KEY *ec
 DEFINEFUNC2(size_t, EC_get_builtin_curves, EC_builtin_curve * r, r, size_t nitems, nitems, return 0, return)
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
 DEFINEFUNC(int, EC_curve_nist2nid, const char *name, name, return 0, return)
+DEFINEFUNC3(int, SSL_CTX_set1_groups, SSL_CTX *a, a, int *b, b, int c, c, return -1, return)
 #endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
 #endif // OPENSSL_NO_EC
 
@@ -658,8 +659,8 @@ static QPair<QLibrary*, QLibrary*> loadO
 #endif
 #if defined(SHLIB_VERSION_NUMBER) && !defined(Q_OS_QNX) // on QNX, the libs are always libssl.so and libcrypto.so
     // first attempt: the canonical name is libssl.so.<SHLIB_VERSION_NUMBER>
-    libssl->setFileNameAndVersion(QLatin1String("ssl"), QLatin1String(SHLIB_VERSION_NUMBER));
-    libcrypto->setFileNameAndVersion(QLatin1String("crypto"), QLatin1String(SHLIB_VERSION_NUMBER));
+    libssl->setFileNameAndVersion(QLatin1String("%%OPENSSLLIB%%/libssl"), QLatin1String(SHLIB_VERSION_NUMBER));
+    libcrypto->setFileNameAndVersion(QLatin1String("%%OPENSSLLIB%%/libcrypto"), QLatin1String(SHLIB_VERSION_NUMBER));
     if (libcrypto->load() && libssl->load()) {
         // libssl.so.<SHLIB_VERSION_NUMBER> and libcrypto.so.<SHLIB_VERSION_NUMBER> found
         return pair;
@@ -676,8 +677,8 @@ static QPair<QLibrary*, QLibrary*> loadO
     //  OS X's /usr/lib/libssl.dylib, /usr/lib/libcrypto.dylib will be picked up in the third
     //    attempt, _after_ <bundle>/Contents/Frameworks has been searched.
     //  iOS does not ship a system libssl.dylib, libcrypto.dylib in the first place.
-    libssl->setFileNameAndVersion(QLatin1String("ssl"), -1);
-    libcrypto->setFileNameAndVersion(QLatin1String("crypto"), -1);
+    libssl->setFileNameAndVersion(QLatin1String("%%OPENSSLLIB%%/libssl"), -1);
+    libcrypto->setFileNameAndVersion(QLatin1String("%%OPENSSLLIB%%/libcrypto"), -1);
     if (libcrypto->load() && libssl->load()) {
         // libssl.so.0 and libcrypto.so.0 found
         return pair;
@@ -982,8 +983,10 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(EC_KEY_free)
     RESOLVEFUNC(EC_get_builtin_curves)
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
-    if (q_SSLeay() >= 0x10002000L)
+    if (q_SSLeay() >= 0x10002000L) {
         RESOLVEFUNC(EC_curve_nist2nid)
+        RESOLVEFUNC(SSL_CTX_set1_groups)
+	}
 #endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
 #endif // OPENSSL_NO_EC
     RESOLVEFUNC(PKCS12_parse)
