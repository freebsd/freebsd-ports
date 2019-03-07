--- rar_fmt_plug.c.orig	2014-12-18 07:59:02 UTC
+++ rar_fmt_plug.c
@@ -48,15 +48,7 @@ john_register_one(&fmt_rar);
 #else
 
 #include <string.h>
-#include <assert.h>
 #include <errno.h>
-#include <openssl/engine.h>
-#include <openssl/evp.h>
-#include <openssl/ssl.h>
-
-#include "arch.h"
-#include "sha.h"
-
 #if AC_BUILT
 #include "autoconfig.h"
 #endif
@@ -71,6 +63,8 @@ john_register_one(&fmt_rar);
 #include <sys/mman.h>
 #endif
 
+#include "arch.h"
+#include "sha.h"
 #include "crc32.h"
 #include "misc.h"
 #include "common.h"
@@ -119,9 +113,7 @@ john_register_one(&fmt_rar);
 
 #ifdef _OPENMP
 #include <omp.h>
-#include <pthread.h>
 #define OMP_SCALE		4
-static pthread_mutex_t *lockarray;
 #endif
 
 #include "memdbg.h"
@@ -198,71 +190,6 @@ static struct fmt_tests cpu_tests[] = {
 	{NULL}
 };
 
-#if defined (_OPENMP)
-static void lock_callback(int mode, int type, const char *file, int line)
-{
-	(void)file;
-	(void)line;
-	if (mode & CRYPTO_LOCK)
-		pthread_mutex_lock(&(lockarray[type]));
-	else
-		pthread_mutex_unlock(&(lockarray[type]));
-}
-
-static unsigned long thread_id(void)
-{
-	return omp_get_thread_num();
-}
-
-static void init_locks(void)
-{
-	int i;
-	lockarray = (pthread_mutex_t*) OPENSSL_malloc(CRYPTO_num_locks() * sizeof(pthread_mutex_t));
-	for (i = 0; i < CRYPTO_num_locks(); i++)
-		pthread_mutex_init(&(lockarray[i]), NULL);
-	CRYPTO_set_id_callback(thread_id);
-	CRYPTO_set_locking_callback(lock_callback);
-}
-#endif	/* _OPENMP */
-
-/* Use AES-NI if available. This is not supported with low-level calls,
-   we have to use EVP) */
-static void init_aesni(void)
-{
-	ENGINE *e;
-	const char *engine_id = "aesni";
-
-	ENGINE_load_builtin_engines();
-	e = ENGINE_by_id(engine_id);
-	if (!e) {
-		//fprintf(stderr, "AES-NI engine not available\n");
-		return;
-	}
-	if (!ENGINE_init(e)) {
-		fprintf(stderr, "AES-NI engine could not init\n");
-		ENGINE_free(e);
-		return;
-	}
-	if (!ENGINE_set_default(e, ENGINE_METHOD_ALL & ~ENGINE_METHOD_RAND)) {
-		/* This should only happen when 'e' can't initialise, but the
-		 * previous statement suggests it did. */
-		fprintf(stderr, "AES-NI engine initialized but then failed\n");
-		abort();
-	}
-	ENGINE_finish(e);
-	ENGINE_free(e);
-}
-
-#ifndef __APPLE__ /* Apple segfaults on this :) */
-static void openssl_cleanup(void)
-{
-	ENGINE_cleanup();
-	ERR_free_strings();
-	CRYPTO_cleanup_all_ex_data();
-	EVP_cleanup();
-}
-#endif
-
 #undef set_key
 static void set_key(char *key, int index)
 {
@@ -418,7 +345,6 @@ static void init(struct fmt_main *self)
 	omp_t = omp_get_max_threads();
 	self->params.min_keys_per_crypt *= omp_t;
 	self->params.max_keys_per_crypt = omp_t * OMP_SCALE * MAX_KEYS_PER_CRYPT;
-	init_locks();
 #endif /* _OPENMP */
 
 	if (pers_opts.target_enc == UTF_8)
@@ -436,14 +362,6 @@ static void init(struct fmt_main *self)
 	self->params.benchmark_comment = " (1-16 characters)";
 #endif
 
-	/* OpenSSL init */
-	init_aesni();
-	SSL_load_error_strings();
-	SSL_library_init();
-	OpenSSL_add_all_algorithms();
-#ifndef __APPLE__
-	atexit(openssl_cleanup);
-#endif
 	/* CRC-32 table init, do it before we start multithreading */
 	{
 		CRC32_t crc;
@@ -716,53 +634,43 @@ static int crypt_all(int *pcount, struct db_salt *salt
 #pragma omp parallel for
 #endif
 	for (index = 0; index < count; index++) {
-		int i16 = index*16;
-		unsigned int inlen = 16;
-		int outlen;
-		EVP_CIPHER_CTX aes_ctx;
+		AES_KEY aes_ctx;
+		unsigned char *key = &aes_key[index * 16];
+		unsigned char *iv = &aes_iv[index * 16];
 
-		EVP_CIPHER_CTX_init(&aes_ctx);
-		EVP_DecryptInit_ex(&aes_ctx, EVP_aes_128_cbc(), NULL, &aes_key[i16], &aes_iv[i16]);
-		EVP_CIPHER_CTX_set_padding(&aes_ctx, 0);
+		AES_set_decrypt_key(key, 128, &aes_ctx);
 
 		//fprintf(stderr, "key %s\n", utf16_to_enc((UTF16*)&saved_key[index * UNICODE_LENGTH]));
 		/* AES decrypt, uses aes_iv, aes_key and blob */
 		if (cur_file->type == 0) {	/* rar-hp mode */
 			unsigned char plain[16];
 
-			outlen = 0;
+			AES_cbc_encrypt(cur_file->blob, plain, 16,
+			                &aes_ctx, iv, AES_DECRYPT);
 
-			EVP_DecryptUpdate(&aes_ctx, plain, &outlen, cur_file->blob, inlen);
-			EVP_DecryptFinal_ex(&aes_ctx, &plain[outlen], &outlen);
-
 			cracked[index] = !memcmp(plain, "\xc4\x3d\x7b\x00\x40\x07\x00", 7);
-
 		} else {
-
 			if (cur_file->method == 0x30) {	/* stored, not deflated */
 				CRC32_t crc;
 				unsigned char crc_out[4];
-				unsigned char plain[0x8010];
+				unsigned char plain[0x8000];
 				unsigned long long size = cur_file->unp_size;
 				unsigned char *cipher = cur_file->blob;
 
 				/* Use full decryption with CRC check.
 				   Compute CRC of the decompressed plaintext */
 				CRC32_Init(&crc);
-				outlen = 0;
 
-				while (size > 0x8000) {
-					inlen = 0x8000;
+				while (size) {
+					unsigned int inlen = (size > 0x8000) ? 0x8000 : size;
 
-					EVP_DecryptUpdate(&aes_ctx, plain, &outlen, cipher, inlen);
-					CRC32_Update(&crc, plain, outlen > size ? size : outlen);
-					size -= outlen;
+					AES_cbc_encrypt(cipher, plain, inlen,
+					                &aes_ctx, iv, AES_DECRYPT);
+
+					CRC32_Update(&crc, plain, inlen);
+					size -= inlen;
 					cipher += inlen;
 				}
-				EVP_DecryptUpdate(&aes_ctx, plain, &outlen, cipher, (size + 15) & ~0xf);
-				EVP_DecryptFinal_ex(&aes_ctx, &plain[outlen], &outlen);
-				size += outlen;
-				CRC32_Update(&crc, plain, size);
 				CRC32_Final(crc_out, crc);
 
 				/* Compare computed CRC with stored CRC */
@@ -771,15 +679,16 @@ static int crypt_all(int *pcount, struct db_salt *salt
 				const int solid = 0;
 				unpack_data_t *unpack_t;
 				unsigned char plain[20];
+				unsigned char pre_iv[16];
 
 				cracked[index] = 0;
 
+				memcpy(pre_iv, iv, 16);
+
 				/* Decrypt just one block for early rejection */
-				outlen = 0;
-				EVP_DecryptUpdate(&aes_ctx, plain, &outlen, cur_file->blob, 16);
-				EVP_DecryptFinal_ex(&aes_ctx, &plain[outlen], &outlen);
+				AES_cbc_encrypt(cur_file->blob, plain, 16,
+				                &aes_ctx, pre_iv, AES_DECRYPT);
 
-#if 1
 				/* Early rejection */
 				if (plain[0] & 0x80) {
 					// PPM checks here.
@@ -792,10 +701,10 @@ static int crypt_all(int *pcount, struct db_salt *salt
 					    !check_huffman(plain)) // Huffman table check
 						goto bailOut;
 				}
-#endif
+
 				/* Reset stuff for full check */
-				EVP_DecryptInit_ex(&aes_ctx, EVP_aes_128_cbc(), NULL, &aes_key[i16], &aes_iv[i16]);
-				EVP_CIPHER_CTX_set_padding(&aes_ctx, 0);
+				AES_set_decrypt_key(key, 128, &aes_ctx);
+
 #ifdef _OPENMP
 				unpack_t = &unpack_data[omp_get_thread_num()];
 #else
@@ -804,16 +713,15 @@ static int crypt_all(int *pcount, struct db_salt *salt
 				unpack_t->max_size = cur_file->unp_size;
 				unpack_t->dest_unp_size = cur_file->unp_size;
 				unpack_t->pack_size = cur_file->pack_size;
-				unpack_t->iv = &aes_iv[i16];
+				unpack_t->iv = iv;
 				unpack_t->ctx = &aes_ctx;
-				unpack_t->key = &aes_key[i16];
+				unpack_t->key = key;
 
 				if (rar_unpack29(cur_file->blob, solid, unpack_t))
 					cracked[index] = !memcmp(&unpack_t->unp_crc, &cur_file->crc.c, 4);
 bailOut:;
 			}
 		}
-		EVP_CIPHER_CTX_cleanup(&aes_ctx);
 	}
 	return count;
 }
