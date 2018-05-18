* Boilerplate for SSL_CTX_set1_groups() used in qsslcontext_openssl.cpp
*
* Prepend the path of the SSL libraries used for building so the same libraries are
* found and loaded at runtime. Normal search finds base SSL libraries before ports.
*
--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2017-11-30 13:49:46 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -524,6 +524,9 @@ DEFINEFUNC(void, EC_KEY_free, EC_KEY *ecdh, ecdh, retu
 DEFINEFUNC2(size_t, EC_get_builtin_curves, EC_builtin_curve * r, r, size_t nitems, nitems, return 0, return)
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
 DEFINEFUNC(int, EC_curve_nist2nid, const char *name, name, return 0, return)
+#if defined(LIBRESSL_VERSION_NUMBER)
+DEFINEFUNC3(int, SSL_CTX_set1_groups, SSL_CTX *a, a, int *b, b, int c, c, return -1, return)
+#endif // defined(LIBRESSL_VERSION_NUMBER)
 #endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
 #endif // OPENSSL_NO_EC
 
@@ -769,8 +772,8 @@ static QPair<QLibrary*, QLibrary*> loadOpenSsl()
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
@@ -787,8 +790,8 @@ static QPair<QLibrary*, QLibrary*> loadOpenSsl()
     //  macOS's /usr/lib/libssl.dylib, /usr/lib/libcrypto.dylib will be picked up in the third
     //    attempt, _after_ <bundle>/Contents/Frameworks has been searched.
     //  iOS does not ship a system libssl.dylib, libcrypto.dylib in the first place.
-    libssl->setFileNameAndVersion(QLatin1String("ssl"), -1);
-    libcrypto->setFileNameAndVersion(QLatin1String("crypto"), -1);
+    libssl->setFileNameAndVersion(QLatin1String("%%OPENSSLLIB%%/libssl"), -1);
+    libcrypto->setFileNameAndVersion(QLatin1String("%%OPENSSLLIB%%/libcrypto"), -1);
     if (libcrypto->load() && libssl->load()) {
         // libssl.so.0 and libcrypto.so.0 found
         return pair;
@@ -979,10 +982,9 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(OPENSSL_add_all_algorithms_conf)
     RESOLVEFUNC(SSLeay)
 
-    if (!_q_SSLeay || q_SSLeay() >= 0x10100000L) {
+    if (!_q_SSLeay) {
         // OpenSSL 1.1 has deprecated and removed SSLeay. We consider a failure to
         // resolve this symbol as a failure to resolve symbols.
-        // The right operand of '||' above is ... a bit of paranoia.
         delete libs.first;
         delete libs.second;
         qCWarning(lcSsl, "Incompatible version of OpenSSL");
@@ -994,8 +996,12 @@ bool q_resolveOpenSslSymbols()
 
 #ifndef OPENSSL_NO_EC
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
-    if (q_SSLeay() >= 0x10002000L)
+    if (q_SSLeay() >= 0x10002000L) {
         RESOLVEFUNC(EC_curve_nist2nid)
+#if defined(LIBRESSL_VERSION_NUMBER)
+        RESOLVEFUNC(SSL_CTX_set1_groups)
+#endif // defined(LIBRESSL_VERSION_NUMBER)
+    }
 #endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
 #endif // OPENSSL_NO_EC
 
@@ -1017,7 +1023,7 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(EC_GROUP_get_degree)
 #endif
     RESOLVEFUNC(BN_num_bits)
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if !defined(BN_is_word)
     RESOLVEFUNC(BN_is_word)
 #endif
     RESOLVEFUNC(BN_mod_word)
