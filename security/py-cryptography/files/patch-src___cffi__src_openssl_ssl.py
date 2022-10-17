--- src/_cffi_src/openssl/ssl.py.orig	2022-10-17 11:17:08 UTC
+++ src/_cffi_src/openssl/ssl.py
@@ -515,12 +515,7 @@ CUSTOMIZATIONS = """
 // users have upgraded. PersistentlyDeprecated2020
 static const long Cryptography_HAS_TLSEXT_HOSTNAME = 1;
 
-#if CRYPTOGRAPHY_IS_LIBRESSL
-static const long Cryptography_HAS_VERIFIED_CHAIN = 0;
-Cryptography_STACK_OF_X509 *(*SSL_get0_verified_chain)(const SSL *) = NULL;
-#else
 static const long Cryptography_HAS_VERIFIED_CHAIN = 1;
-#endif
 
 #if CRYPTOGRAPHY_OPENSSL_LESS_THAN_111
 static const long Cryptography_HAS_KEYLOG = 0;
@@ -583,13 +578,6 @@ static const long Cryptography_HAS_TLS_ST = 1;
 static const long Cryptography_HAS_TLS_ST = 0;
 static const long TLS_ST_BEFORE = 0;
 static const long TLS_ST_OK = 0;
-#endif
-
-#if CRYPTOGRAPHY_IS_LIBRESSL
-static const long SSL_OP_NO_DTLSv1 = 0;
-static const long SSL_OP_NO_DTLSv1_2 = 0;
-long (*DTLS_set_link_mtu)(SSL *, long) = NULL;
-long (*DTLS_get_link_min_mtu)(SSL *) = NULL;
 #endif
 
 static const long Cryptography_HAS_DTLS = 1;
