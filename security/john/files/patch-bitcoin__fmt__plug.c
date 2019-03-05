--- bitcoin_fmt_plug.c.orig	2014-12-18 07:59:02 UTC
+++ bitcoin_fmt_plug.c
@@ -15,33 +15,32 @@
  * Thanks to Solar for asking to add support for bitcoin wallet files.
  */
 
-#include "arch.h"
-#include <openssl/opensslv.h>
-#if (AC_BUILT && HAVE_EVP_SHA512) || \
-	(!AC_BUILT && OPENSSL_VERSION_NUMBER >= 0x0090708f)
-
 #if FMT_EXTERNS_H
 extern struct fmt_main fmt_bitcoin;
 #elif FMT_REGISTERS_H
 john_register_one(&fmt_bitcoin);
 #else
 
-#include <openssl/evp.h>
 #include <string.h>
+#ifdef _OPENMP
+#include <omp.h>
+#ifndef OMP_SCALE
+#define OMP_SCALE               1
+#endif
+static int omp_t = 1;
+#endif
+
+#include "arch.h"
 #include "misc.h"
 #include "common.h"
 #include "formats.h"
 #include "params.h"
 #include "options.h"
 #include "sha2.h"
+#include "aes/aes.h"
 #include "stdint.h"
 #include "johnswap.h"
 #include "sse-intrinsics.h"
-#ifdef _OPENMP
-#include <omp.h>
-#define OMP_SCALE               1
-static int omp_t = 1;
-#endif
 #include "memdbg.h"
 
 #define FORMAT_LABEL		"Bitcoin"
@@ -73,6 +72,7 @@ static int omp_t = 1;
 #endif
 
 #define SZ 			128
+#define PADDING		"\x10\x10\x10\x10\x10\x10\x10\x10\x10\x10\x10\x10\x10\x10\x10\x10"
 
 static struct fmt_tests bitcoin_tests[] = {
 	/* bitcoin wallet hashes */
@@ -265,10 +265,7 @@ static int crypt_all(int *pcount, struct db_salt *salt
 #endif
 	{
 		unsigned char output[SZ];
-		int fOk;
 		SHA512_CTX sha_ctx;
-		EVP_CIPHER_CTX ctx;
-		int nPLen, nFLen;
 		int i;
 
 #ifdef MMX_COEF_SHA512
@@ -316,6 +313,7 @@ static int crypt_all(int *pcount, struct db_salt *salt
 		alter_endianity_to_BE64(key_iv, 6 * MAX_KEYS_PER_CRYPT);
 
 		for (index2 = 0; index2 < MAX_KEYS_PER_CRYPT; index2++) {
+			AES_KEY aes_key;
 			unsigned char key[32];
 			unsigned char iv[16];
 
@@ -325,26 +323,21 @@ static int crypt_all(int *pcount, struct db_salt *salt
 			for (i = 0; i < sizeof(iv)/sizeof(ARCH_WORD_64); i++)   // the derived iv
 				((ARCH_WORD_64 *)iv)[i]  = key_iv[MMX_COEF_SHA512*(sizeof(key)/sizeof(ARCH_WORD_64) + i) + index2];
 
-			/* NOTE: write our code instead of using following high-level OpenSSL functions */
-			EVP_CIPHER_CTX_init(&ctx);
-			fOk = EVP_DecryptInit_ex(&ctx, EVP_aes_256_cbc(), NULL, key, iv);
-			if (fOk)
-				fOk = EVP_DecryptUpdate(&ctx, output, &nPLen, cur_salt->cry_master, cur_salt->cry_master_length);
-			if (fOk)
-				fOk = EVP_DecryptFinal_ex(&ctx, output + nPLen, &nFLen);
-			EVP_CIPHER_CTX_cleanup(&ctx);
-			// a decrypted mkey is exactly 32 bytes in len; ossl has already checked the padding (16 0x0f's) for us
-			if (fOk && nPLen + nFLen == 32) {
+			AES_set_decrypt_key(key, 256, &aes_key);
+			AES_cbc_encrypt(cur_salt->cry_master, output, cur_salt->cry_master_length, &aes_key, iv, AES_DECRYPT);
+
+			if (!memcmp(output + 32, PADDING, 16)) {
 				cracked[index + index2] = 1;
 #ifdef _OPENMP
 #pragma omp atomic
 #endif
 				any_cracked |= 1;
 			}
-
 		}
 #else
+		AES_KEY aes_key;
 		unsigned char key_iv[SHA512_DIGEST_LENGTH];  // buffer for both the derived key and iv
+
 		SHA512_Init(&sha_ctx);
 		SHA512_Update(&sha_ctx, saved_key[index], strlen(saved_key[index]));
 		SHA512_Update(&sha_ctx, cur_salt->cry_salt, cur_salt->cry_salt_length);
@@ -354,16 +347,11 @@ static int crypt_all(int *pcount, struct db_salt *salt
 			SHA512_Update(&sha_ctx, key_iv, SHA512_DIGEST_LENGTH);
 			SHA512_Final(key_iv, &sha_ctx);
 		}
-		/* NOTE: write our code instead of using following high-level OpenSSL functions */
-		EVP_CIPHER_CTX_init(&ctx);
-		fOk = EVP_DecryptInit_ex(&ctx, EVP_aes_256_cbc(), NULL, key_iv, key_iv+32);
-		if (fOk)
-			fOk = EVP_DecryptUpdate(&ctx, output, &nPLen, cur_salt->cry_master, cur_salt->cry_master_length);
-		if (fOk)
-			fOk = EVP_DecryptFinal_ex(&ctx, output + nPLen, &nFLen);
-		EVP_CIPHER_CTX_cleanup(&ctx);
-		// a decrypted mkey is exactly 32 bytes in len; ossl has already checked the padding (16 0x0f's) for us
-		if (fOk && nPLen + nFLen == 32) {
+
+		AES_set_decrypt_key(key_iv, 256, &aes_key);
+		AES_cbc_encrypt(cur_salt->cry_master, output, cur_salt->cry_master_length, &aes_key, key_iv + 32, AES_DECRYPT);
+
+		if (!memcmp(output + 32, PADDING, 16)) {
 			cracked[index] = 1;
 #ifdef _OPENMP
 #pragma omp atomic
@@ -471,5 +459,3 @@ struct fmt_main fmt_bitcoin = {
 };
 
 #endif /* plugin stanza */
-
-#endif /* OpenSSL requirement */
