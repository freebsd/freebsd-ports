--- src/p11_key.c.orig	2017-01-26 21:19:45 UTC
+++ src/p11_key.c
@@ -138,7 +138,7 @@ int pkcs11_generate_key(PKCS11_TOKEN *to
 	EVP_PKEY *pk;
 	RSA *rsa;
 	BIO *err;
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	BIGNUM *exp = NULL;
 	BN_GENCB *gencb = NULL;
 #endif
@@ -151,7 +151,7 @@ int pkcs11_generate_key(PKCS11_TOKEN *to
 
 	err = BIO_new_fp(stderr, BIO_NOCLOSE);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	exp = BN_new();
 	rsa = RSA_new();
 	gencb = BN_GENCB_new();
@@ -247,7 +247,7 @@ static int pkcs11_store_key(PKCS11_TOKEN
 		pkcs11_addattr_bool(attrs + n++, CKA_VERIFY, TRUE);
 		pkcs11_addattr_bool(attrs + n++, CKA_WRAP, TRUE);
 	}
-#if OPENSSL_VERSION_NUMBER >= 0x10100003L
+#if OPENSSL_VERSION_NUMBER >= 0x10100003L && !defined(LIBRESSL_VERSION_NUMBER)
 	if (EVP_PKEY_base_id(pk) == EVP_PKEY_RSA) {
 		RSA *rsa = EVP_PKEY_get1_RSA(pk);
 #else
@@ -255,7 +255,7 @@ static int pkcs11_store_key(PKCS11_TOKEN
 		RSA *rsa = pk->pkey.rsa;
 #endif
 		pkcs11_addattr_int(attrs + n++, CKA_KEY_TYPE, CKK_RSA);
-#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L && !defined(LIBRESSL_VERSION_NUMBER)
 		RSA_get0_key(rsa, &rsa_n, &rsa_e, &rsa_d);
 		RSA_get0_factors(rsa, &rsa_p, &rsa_q);
 #else
@@ -325,7 +325,7 @@ EVP_PKEY *pkcs11_get_key(PKCS11_KEY *key
 				fprintf(stderr, "Missing CKA_ALWAYS_AUTHENTICATE attribute\n");
 		}
 	}
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	EVP_PKEY_up_ref(key->evp_key);
 #else
 	CRYPTO_add(&key->evp_key->references, 1, CRYPTO_LOCK_EVP_PKEY);
