Index: src/mosquitto_passwd.c
===================================================================
--- src/mosquitto_passwd.c.orig
+++ src/mosquitto_passwd.c
@@ -141,7 +141,7 @@ int output_new_password(FILE *fptr, cons
 	unsigned char hash[EVP_MAX_MD_SIZE];
 	unsigned int hash_len;
 	const EVP_MD *digest;
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(HAVE_OPENSSL_OPAQUE_STRUCTS)
 	EVP_MD_CTX context;
 #else
 	EVP_MD_CTX *context;
@@ -168,7 +168,7 @@ int output_new_password(FILE *fptr, cons
 		return 1;
 	}
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(HAVE_OPENSSL_OPAQUE_STRUCTS)
 	EVP_MD_CTX_init(&context);
 	EVP_DigestInit_ex(&context, digest, NULL);
 	EVP_DigestUpdate(&context, password, strlen(password));
