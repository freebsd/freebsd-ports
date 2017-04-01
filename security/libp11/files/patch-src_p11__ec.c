--- src/p11_ec.c.orig	2017-01-26 21:19:45 UTC
+++ src/p11_ec.c
@@ -37,7 +37,7 @@
 #include <openssl/ecdh.h>
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100004L
+#if OPENSSL_VERSION_NUMBER >= 0x10100004L && !defined(LIBRESSL_VERSION_NUMBER)
 typedef int (*compute_key_fn)(unsigned char **, size_t *,
 	const EC_POINT *, const EC_KEY *);
 #else
@@ -73,7 +73,7 @@ struct ecdsa_method {
 
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
 
-#if OPENSSL_VERSION_NUMBER < 0x10002000L
+#if OPENSSL_VERSION_NUMBER < 0x10002000L || defined(LIBRESSL_VERSION_NUMBER)
 
 /* Define missing functions */
 
@@ -104,7 +104,7 @@ void ECDSA_METHOD_set_sign(ECDSA_METHOD 
 
 /********** Missing ECDH_METHOD functions for OpenSSL < 1.1.0 */
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 /* ecdh_method maintains unchanged layout between 0.9.8 and 1.0.2 */
 
@@ -156,7 +156,7 @@ static void alloc_ec_ex_index()
 {
 	if (ec_ex_index == 0) {
 		while (ec_ex_index == 0) /* Workaround for OpenSSL RT3710 */
-#if OPENSSL_VERSION_NUMBER >= 0x10100002L
+#if OPENSSL_VERSION_NUMBER >= 0x10100002L && !defined(LIBRESSL_VERSION_NUMBER)
 			ec_ex_index = EC_KEY_get_ex_new_index(0, "libp11 ec_key",
 				NULL, NULL, NULL);
 #else
@@ -265,7 +265,7 @@ static EVP_PKEY *pkcs11_get_evp_key_ec(P
 	EVP_PKEY_set1_EC_KEY(pk, ec); /* Also increments the ec ref count */
 
 	if (key->isPrivate) {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 		EC_KEY_set_method(ec, PKCS11_get_ec_key_method());
 #else
 		ECDSA_set_method(ec, PKCS11_get_ecdsa_method());
@@ -275,7 +275,7 @@ static EVP_PKEY *pkcs11_get_evp_key_ec(P
 	/* TODO: Retrieve the ECDSA private key object attributes instead,
 	 * unless the key has the "sensitive" attribute set */
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	EC_KEY_set_ex_data(ec, ec_ex_index, key);
 #else
 	ECDSA_set_ex_data(ec, ec_ex_index, key);
@@ -345,14 +345,14 @@ static ECDSA_SIG *pkcs11_ecdsa_sign_sig(
 	(void)kinv; /* Precomputed values are not used for PKCS#11 */
 	(void)rp; /* Precomputed values are not used for PKCS#11 */
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	key = (PKCS11_KEY *)EC_KEY_get_ex_data(ec, ec_ex_index);
 #else
 	key = (PKCS11_KEY *)ECDSA_get_ex_data(ec, ec_ex_index);
 #endif
 	if (key == NULL) {
 		sign_sig_fn orig_sign_sig;
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 		const EC_KEY_METHOD *meth = EC_KEY_OpenSSL();
 		EC_KEY_METHOD_get_sign((EC_KEY_METHOD *)meth,
 			NULL, NULL, &orig_sign_sig);
@@ -385,7 +385,7 @@ static ECDSA_SIG *pkcs11_ecdsa_sign_sig(
 	sig = ECDSA_SIG_new();
 	if (sig == NULL)
 		return NULL;
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	ECDSA_SIG_set0(sig, r, s);
 #else
 	BN_free(sig->r);
@@ -515,7 +515,7 @@ static int pkcs11_ecdh_derive(unsigned c
 	return 0;
 }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100004L
+#if OPENSSL_VERSION_NUMBER >= 0x10100004L && !defined(LIBRESSL_VERSION_NUMBER)
 
 /**
  * ECDH key derivation method (replaces ossl_ecdh_compute_key)
@@ -578,7 +578,7 @@ static int pkcs11_ec_ckey(void *out, siz
 	size_t buflen;
 	int rv;
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	key = (PKCS11_KEY *)EC_KEY_get_ex_data(ecdh, ec_ex_index);
 #else
 	key = (PKCS11_KEY *)ECDSA_get_ex_data((EC_KEY *)ecdh, ec_ex_index);
@@ -623,7 +623,7 @@ static int pkcs11_ec_ckey(void *out, siz
 /* New way to allocate an ECDSA_METOD object */
 /* OpenSSL 1.1 has single method  EC_KEY_METHOD for ECDSA and ECDH */
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 
 EC_KEY_METHOD *PKCS11_get_ec_key_method(void)
 {
