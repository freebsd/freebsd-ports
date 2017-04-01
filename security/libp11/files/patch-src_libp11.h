--- src/libp11.h.orig	2017-01-26 21:19:45 UTC
+++ src/libp11.h
@@ -370,7 +370,7 @@ extern int PKCS11_generate_random(PKCS11
  */
 RSA_METHOD *PKCS11_get_rsa_method(void);
 /* Also define unsupported methods to retain backward compatibility */
-#if OPENSSL_VERSION_NUMBER >= 0x10100002L
+#if OPENSSL_VERSION_NUMBER >= 0x10100002L && !defined(LIBRESSL_VERSION_NUMBER)
 EC_KEY_METHOD *PKCS11_get_ec_key_method(void);
 void *PKCS11_get_ecdsa_method(void);
 void *PKCS11_get_ecdh_method(void);
