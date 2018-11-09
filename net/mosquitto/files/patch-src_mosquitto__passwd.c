 lib/mosquitto_internal.h | 3 +++
 src/mosquitto_passwd.c   | 4 ++--
 src/security_default.c   | 2 +-
 3 files changed, 6 insertions(+), 3 deletions(-)

--- src/mosquitto_passwd.c.orig	2018-10-11 00:27:05 UTC
+++ src/mosquitto_passwd.c
@@ -17,6 +17,7 @@ Contributors:
 #include "config.h"
 
 #include <errno.h>
+#include <openssl/opensslv.h>
 #include <openssl/evp.h>
 #include <openssl/rand.h>
 #include <openssl/buffer.h>
@@ -99,7 +100,7 @@ int output_new_password(FILE *fptr, const char *userna
 	unsigned char hash[EVP_MAX_MD_SIZE];
 	unsigned int hash_len;
 	const EVP_MD *digest;
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#ifdef HAVE_OPENSSL_OPAQUE_STRUCTS 
 	EVP_MD_CTX context;
 #else
 	EVP_MD_CTX *context;
@@ -126,7 +127,7 @@ int output_new_password(FILE *fptr, const char *userna
 		return 1;
 	}
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L 
 	EVP_MD_CTX_init(&context);
 	EVP_DigestInit_ex(&context, digest, NULL);
 	EVP_DigestUpdate(&context, password, strlen(password));
