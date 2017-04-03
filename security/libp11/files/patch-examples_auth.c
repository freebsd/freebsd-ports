--- examples/auth.c.orig	2017-01-26 21:19:45 UTC
+++ examples/auth.c
@@ -212,7 +212,7 @@ int main(int argc, char *argv[])
 
 	/* now verify the result */
 	rc = RSA_verify(NID_sha1, random, RANDOM_SIZE,
-#if OPENSSL_VERSION_NUMBER >= 0x10100003L
+#if OPENSSL_VERSION_NUMBER >= 0x10100003L && !defined(LIBRESSL_VERSION_NUMBER)
 			signature, siglen, EVP_PKEY_get0_RSA(pubkey));
 #else
 			signature, siglen, pubkey->pkey.rsa);
