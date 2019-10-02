Redefine SSL stack functions to their proper symbols in LibreSSL.
Also reference a redefined DSA_bits() that does not natively exist
in LibreSSL.

Ensure that we link to the correct ssl library selected in
DEFAULT_VERSIONS.

Do not define SSL_CONF_CTX symbols absent from LibreSSL.

--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2018-12-03 11:15:26 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -152,6 +152,14 @@ DEFINEFUNC2(int, BN_is_word, BIGNUM *a, a, BN_ULONG w,
 DEFINEFUNC(int, EVP_CIPHER_CTX_reset, EVP_CIPHER_CTX *c, c, return 0, return)
 DEFINEFUNC(int, EVP_PKEY_base_id, EVP_PKEY *a, a, return NID_undef, return)
 DEFINEFUNC(int, RSA_bits, RSA *a, a, return 0, return)
+#ifdef LIBRESSL_VERSION_NUMBER
+DEFINEFUNC(int, sk_num, OPENSSL_STACK *a, a, return -1, return)
+DEFINEFUNC2(void, sk_pop_free, OPENSSL_STACK *a, a, void (*b)(void*), b, return, DUMMYARG)
+DEFINEFUNC(OPENSSL_STACK *, sk_new_null, DUMMYARG, DUMMYARG, return nullptr, return)
+DEFINEFUNC2(void, sk_push, OPENSSL_STACK *a, a, void *b, b, return, DUMMYARG)
+DEFINEFUNC(void, sk_free, OPENSSL_STACK *a, a, return, DUMMYARG)
+DEFINEFUNC2(void *, sk_value, OPENSSL_STACK *a, a, int b, b, return nullptr, return)
+#else
 DEFINEFUNC(int, DSA_bits, DSA *a, a, return 0, return)
 DEFINEFUNC(int, OPENSSL_sk_num, OPENSSL_STACK *a, a, return -1, return)
 DEFINEFUNC2(void, OPENSSL_sk_pop_free, OPENSSL_STACK *a, a, void (*b)(void*), b, return, DUMMYARG)
@@ -159,6 +167,7 @@ DEFINEFUNC(OPENSSL_STACK *, OPENSSL_sk_new_null, DUMMY
 DEFINEFUNC2(void, OPENSSL_sk_push, OPENSSL_STACK *a, a, void *b, b, return, DUMMYARG)
 DEFINEFUNC(void, OPENSSL_sk_free, OPENSSL_STACK *a, a, return, DUMMYARG)
 DEFINEFUNC2(void *, OPENSSL_sk_value, OPENSSL_STACK *a, a, int b, b, return nullptr, return)
+#endif
 DEFINEFUNC(int, SSL_session_reused, SSL *a, a, return 0, return)
 DEFINEFUNC2(unsigned long, SSL_CTX_set_options, SSL_CTX *ctx, ctx, unsigned long op, op, return 0, return)
 #ifdef TLS1_3_VERSION
@@ -443,7 +452,7 @@ DEFINEFUNC2(int, SSL_CTX_use_PrivateKey, SSL_CTX *a, a
 DEFINEFUNC2(int, SSL_CTX_use_RSAPrivateKey, SSL_CTX *a, a, RSA *b, b, return -1, return)
 DEFINEFUNC3(int, SSL_CTX_use_PrivateKey_file, SSL_CTX *a, a, const char *b, b, int c, c, return -1, return)
 DEFINEFUNC(X509_STORE *, SSL_CTX_get_cert_store, const SSL_CTX *a, a, return nullptr, return)
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
 DEFINEFUNC(SSL_CONF_CTX *, SSL_CONF_CTX_new, DUMMYARG, DUMMYARG, return nullptr, return);
 DEFINEFUNC(void, SSL_CONF_CTX_free, SSL_CONF_CTX *a, a, return ,return);
 DEFINEFUNC2(void, SSL_CONF_CTX_set_ssl_ctx, SSL_CONF_CTX *a, a, SSL_CTX *b, b, return, return);
@@ -846,8 +855,8 @@ static QPair<QLibrary*, QLibrary*> loadOpenSsl()
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
@@ -876,8 +885,8 @@ static QPair<QLibrary*, QLibrary*> loadOpenSsl()
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
@@ -961,12 +970,21 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(EVP_CIPHER_CTX_reset)
     RESOLVEFUNC(EVP_PKEY_base_id)
     RESOLVEFUNC(RSA_bits)
+#ifdef LIBRESSL_VERSION_NUMBER
+    RESOLVEFUNC(sk_new_null)
+    RESOLVEFUNC(sk_push)
+    RESOLVEFUNC(sk_free)
+    RESOLVEFUNC(sk_num)
+    RESOLVEFUNC(sk_pop_free)
+    RESOLVEFUNC(sk_value)
+#else
     RESOLVEFUNC(OPENSSL_sk_new_null)
     RESOLVEFUNC(OPENSSL_sk_push)
     RESOLVEFUNC(OPENSSL_sk_free)
     RESOLVEFUNC(OPENSSL_sk_num)
     RESOLVEFUNC(OPENSSL_sk_pop_free)
     RESOLVEFUNC(OPENSSL_sk_value)
+#endif
     RESOLVEFUNC(DH_get0_pqg)
     RESOLVEFUNC(SSL_CTX_set_options)
 #ifdef TLS1_3_VERSION
@@ -1001,7 +1019,9 @@ bool q_resolveOpenSslSymbols()
 
     RESOLVEFUNC(SSL_SESSION_get_ticket_lifetime_hint)
     RESOLVEFUNC(DH_bits)
+#ifndef LIBRESSL_VERSION_NUMBER
     RESOLVEFUNC(DSA_bits)
+#endif
 
 #if QT_CONFIG(dtls)
     RESOLVEFUNC(DTLSv1_listen)
@@ -1237,7 +1257,7 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(SSL_CTX_use_RSAPrivateKey)
     RESOLVEFUNC(SSL_CTX_use_PrivateKey_file)
     RESOLVEFUNC(SSL_CTX_get_cert_store);
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
     RESOLVEFUNC(SSL_CONF_CTX_new);
     RESOLVEFUNC(SSL_CONF_CTX_free);
     RESOLVEFUNC(SSL_CONF_CTX_set_ssl_ctx);
