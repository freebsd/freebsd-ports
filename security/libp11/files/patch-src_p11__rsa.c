--- src/p11_rsa.c.orig	2017-01-26 21:19:45 UTC
+++ src/p11_rsa.c
@@ -29,7 +29,7 @@
 
 static int rsa_ex_index = 0;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100003L
+#if OPENSSL_VERSION_NUMBER < 0x10100003L || defined(LIBRESSL_VERSION_NUMBER)
 #define EVP_PKEY_get0_RSA(key) ((key)->pkey.rsa)
 #endif
 
@@ -226,7 +226,7 @@ failure:
 	return NULL;
 
 success:
-#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L && !defined(LIBRESSL_VERSION_NUMBER)
 		RSA_set0_key(rsa, rsa_n, rsa_e, NULL);
 #else
 		rsa->n=rsa_n;
@@ -275,7 +275,7 @@ int pkcs11_get_key_modulus(PKCS11_KEY *k
 
 	if (rsa == NULL)
 		return 0;
-#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L && !defined(LIBRESSL_VERSION_NUMBER)
 	RSA_get0_key(rsa, &rsa_n, NULL, NULL);
 #else
 	rsa_n=rsa->n;
@@ -292,7 +292,7 @@ int pkcs11_get_key_exponent(PKCS11_KEY *
 
 	if (rsa == NULL)
 		return 0;
-#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L && !defined(LIBRESSL_VERSION_NUMBER)
 	RSA_get0_key(rsa, NULL, &rsa_e, NULL);
 #else
 	rsa_e=rsa->e;
@@ -310,7 +310,7 @@ int pkcs11_get_key_size(PKCS11_KEY *key)
 	return RSA_size(rsa);
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100005L
+#if OPENSSL_VERSION_NUMBER < 0x10100005L || defined(LIBRESSL_VERSION_NUMBER)
 
 int (*RSA_meth_get_priv_enc(const RSA_METHOD *meth))
 		(int flen, const unsigned char *from,
@@ -374,7 +374,7 @@ static void alloc_rsa_ex_index()
 static void free_rsa_ex_index()
 {
 	/* CRYPTO_free_ex_index requires OpenSSL version >= 1.1.0-pre1 */
-#if OPENSSL_VERSION_NUMBER >= 0x10100001L
+#if OPENSSL_VERSION_NUMBER >= 0x10100001L && !defined(LIBRESSL_VERSION_NUMBER)
 	if (rsa_ex_index > 0) {
 		CRYPTO_free_ex_index(CRYPTO_EX_INDEX_RSA, rsa_ex_index);
 		rsa_ex_index = 0;
@@ -382,7 +382,7 @@ static void free_rsa_ex_index()
 #endif
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100005L
+#if OPENSSL_VERSION_NUMBER < 0x10100005L || defined(LIBRESSL_VERSION_NUMBER)
 
 static RSA_METHOD *RSA_meth_dup(const RSA_METHOD *meth)
 {
