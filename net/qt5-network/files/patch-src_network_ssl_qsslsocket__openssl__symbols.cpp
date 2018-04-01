* Boilerplate for SSL_CTX_set1_groups() used in qsslcontext_openssl.cpp
*
* Prepend the path of the SSL libraries used for building so the same libraries are
* found and loaded at runtime. Normal search finds base SSL libraries before ports.
*
--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2018-01-16 06:53:43 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -151,7 +151,7 @@ DEFINEFUNC3(int, BIO_read, BIO *a, a, void *b, b, int
 DEFINEFUNC(BIO_METHOD *, BIO_s_mem, void, DUMMYARG, return 0, return)
 DEFINEFUNC3(int, BIO_write, BIO *a, a, const void *b, b, int c, c, return -1, return)
 DEFINEFUNC(int, BN_num_bits, const BIGNUM *a, a, return 0, return)
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if !defined(BN_is_word)
 DEFINEFUNC2(int, BN_is_word, BIGNUM *a, a, BN_ULONG w, w, return 0, return)
 #endif
 DEFINEFUNC2(BN_ULONG, BN_mod_word, const BIGNUM *a, a, BN_ULONG w, w, return static_cast<BN_ULONG>(-1), return)
@@ -453,6 +453,9 @@ DEFINEFUNC(void, EC_KEY_free, EC_KEY *ecdh, ecdh, retu
 DEFINEFUNC2(size_t, EC_get_builtin_curves, EC_builtin_curve * r, r, size_t nitems, nitems, return 0, return)
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
 DEFINEFUNC(int, EC_curve_nist2nid, const char *name, name, return 0, return)
+#if defined(LIBRESSL_VERSION_NUMBER)
+DEFINEFUNC3(int, SSL_CTX_set1_groups, SSL_CTX *a, a, int *b, b, int c, c, return -1, return)
+#endif // defined(LIBRESSL_VERSION_NUMBER)
 #endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
 #endif // OPENSSL_NO_EC
 
@@ -680,8 +683,8 @@ static QPair<QLibrary*, QLibrary*> loadO
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
@@ -698,8 +701,8 @@ static QPair<QLibrary*, QLibrary*> loadO
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
@@ -790,7 +793,7 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(EC_GROUP_get_degree)
 #endif
     RESOLVEFUNC(BN_num_bits)
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if !defined(BN_is_word)
     RESOLVEFUNC(BN_is_word)
 #endif
     RESOLVEFUNC(BN_mod_word)
@@ -1020,8 +1023,12 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(EC_KEY_free)
     RESOLVEFUNC(EC_get_builtin_curves)
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
-    if (q_SSLeay() >= 0x10002000L)
+    if (q_SSLeay() >= 0x10002000L) {
         RESOLVEFUNC(EC_curve_nist2nid)
+#if defined(LIBRESSL_VERSION_NUMBER)
+        RESOLVEFUNC(SSL_CTX_set1_groups)
+#endif // defined(LIBRESSL_VERSION_NUMBER)
+	}
 #endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
 #endif // OPENSSL_NO_EC
     RESOLVEFUNC(PKCS12_parse)
@@ -1030,10 +1037,9 @@ bool q_resolveOpenSslSymbols()
 
     delete libs.first;
     delete libs.second;
-    if (!_q_SSLeay || q_SSLeay() >= 0x10100000L) {
+    if (!_q_SSLeay) {
         // OpenSSL 1.1 deprecated and removed SSLeay. We consider a failure to
         // resolve this symbol as a failure to resolve symbols.
-        // The right operand of '||' above ... a bit of paranoia.
         qCWarning(lcSsl, "Incompatible version of OpenSSL");
         return false;
     }
