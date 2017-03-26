--- examples/decrypt.c.orig	2017-01-26 21:19:45 UTC
+++ examples/decrypt.c
@@ -131,7 +131,7 @@ int main(int argc, char *argv[])
 	}
 
 	/* allocate destination buffer */
-#if OPENSSL_VERSION_NUMBER >= 0x10100003L
+#if OPENSSL_VERSION_NUMBER >= 0x10100003L && !defined(LIBRESSL_VERSION_NUMBER)
 	encrypted = OPENSSL_malloc(RSA_size(EVP_PKEY_get0_RSA(pubkey)));
 #else
 	encrypted = OPENSSL_malloc(RSA_size(pubkey->pkey.rsa));
@@ -143,7 +143,7 @@ int main(int argc, char *argv[])
 
 	/* use public key for encryption */
 	len = RSA_public_encrypt(RANDOM_SIZE, random, encrypted,
-#if OPENSSL_VERSION_NUMBER >= 0x10100003L
+#if OPENSSL_VERSION_NUMBER >= 0x10100003L && !defined(LIBRESSL_VERSION_NUMBER)
 			EVP_PKEY_get0_RSA(pubkey),
 #else
 			pubkey->pkey.rsa,
@@ -200,7 +200,7 @@ loggedin:
 	}
 
 	/* allocate space for decrypted data */
-#if OPENSSL_VERSION_NUMBER >= 0x10100003L
+#if OPENSSL_VERSION_NUMBER >= 0x10100003L && !defined(LIBRESSL_VERSION_NUMBER)
 	decrypted = OPENSSL_malloc(RSA_size(EVP_PKEY_get0_RSA(pubkey)));
 #else
 	decrypted = OPENSSL_malloc(RSA_size(pubkey->pkey.rsa));
