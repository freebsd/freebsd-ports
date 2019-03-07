--- dmg_fmt_plug.c.orig	2014-12-18 07:59:02 UTC
+++ dmg_fmt_plug.c
@@ -56,7 +56,7 @@ john_register_one(&fmt_dmg);
 #include <stdlib.h>
 #include "stdint.h"
 #include <sys/types.h>
-#include <openssl/evp.h>
+#include <openssl/des.h>
 #include <openssl/aes.h>
 #include <openssl/hmac.h>
 #include "filevault.h"
@@ -413,42 +413,36 @@ static void *get_salt(char *ciphertext)
 	return (void *)&cs;
 }
 
-static int apple_des3_ede_unwrap_key1(unsigned char *wrapped_key, int wrapped_key_len, unsigned char *decryptKey)
+static int apple_des3_ede_unwrap_key1(const unsigned char *wrapped_key, const int wrapped_key_len, const unsigned char *decryptKey)
 {
-	EVP_CIPHER_CTX ctx;
+	DES_key_schedule ks1, ks2, ks3;
 	unsigned char TEMP1[sizeof(cur_salt->wrapped_hmac_sha1_key)];
 	unsigned char TEMP2[sizeof(cur_salt->wrapped_hmac_sha1_key)];
-	unsigned char CEKICV[sizeof(cur_salt->wrapped_hmac_sha1_key)];
 	unsigned char IV[8] = { 0x4a, 0xdd, 0xa2, 0x2c, 0x79, 0xe8, 0x21, 0x05 };
-	int outlen, tmplen, i;
+	int outlen, i;
 
-	EVP_CIPHER_CTX_init(&ctx);
-	EVP_DecryptInit_ex(&ctx, EVP_des_ede3_cbc(), NULL, decryptKey, IV);
-	if (!EVP_DecryptUpdate(&ctx, TEMP1, &outlen, wrapped_key, wrapped_key_len)) {
-		goto err;
-	}
-	if (!EVP_DecryptFinal_ex(&ctx, TEMP1 + outlen, &tmplen)) {
-		goto err;
-	}
-	outlen += tmplen;
-	EVP_CIPHER_CTX_cleanup(&ctx);
-	for (i = 0; i < outlen; i++) {
+	DES_set_key((DES_cblock*)(decryptKey +  0), &ks1);
+	DES_set_key((DES_cblock*)(decryptKey +  8), &ks2);
+	DES_set_key((DES_cblock*)(decryptKey + 16), &ks3);
+	DES_ede3_cbc_encrypt(wrapped_key, TEMP1, wrapped_key_len, &ks1, &ks2, &ks3,
+	                     (DES_cblock*)IV, DES_DECRYPT);
+
+	outlen = check_pkcs_pad(TEMP1, wrapped_key_len, 8);
+	if (outlen < 0)
+		return 0;
+
+	for (i = 0; i < outlen; i++)
 		TEMP2[i] = TEMP1[outlen - i - 1];
-	}
-	EVP_CIPHER_CTX_init(&ctx);
-	EVP_DecryptInit_ex(&ctx, EVP_des_ede3_cbc(), NULL, decryptKey, TEMP2);
-	if (!EVP_DecryptUpdate(&ctx, CEKICV, &outlen, TEMP2 + 8, outlen - 8)) {
-		goto err;
-	}
-	if (!EVP_DecryptFinal_ex(&ctx, CEKICV + outlen, &tmplen)) {
-		goto err;
-	}
-	outlen += tmplen;
-	EVP_CIPHER_CTX_cleanup(&ctx);
-	return 0;
-err:
-	EVP_CIPHER_CTX_cleanup(&ctx);
-	return -1;
+
+	outlen -= 8;
+	DES_ede3_cbc_encrypt(TEMP2 + 8, TEMP1, outlen, &ks1, &ks2, &ks3,
+	                     (DES_cblock*)TEMP2, DES_DECRYPT);
+
+	outlen = check_pkcs_pad(TEMP1, outlen, 8);
+	if (outlen < 0)
+		return 0;
+
+	return 1;
 }
 
 static void hash_plugin_check_hash(int index)
@@ -492,22 +486,20 @@ static void hash_plugin_check_hash(int index)
 		for(j = 0; j < SSE_GROUP_SZ_SHA1; ++j) {
 		derived_key = Derived_key[j];
 #endif
-		if ((apple_des3_ede_unwrap_key1(cur_salt->wrapped_aes_key, cur_salt->len_wrapped_aes_key, derived_key) == 0) && (apple_des3_ede_unwrap_key1(cur_salt->wrapped_hmac_sha1_key, cur_salt->len_hmac_sha1_key, derived_key) == 0)) {
+		if (apple_des3_ede_unwrap_key1(cur_salt->wrapped_aes_key, cur_salt->len_wrapped_aes_key, derived_key) &&
+		    apple_des3_ede_unwrap_key1(cur_salt->wrapped_hmac_sha1_key, cur_salt->len_hmac_sha1_key, derived_key)) {
 			cracked[index+j] = 1;
 		}
 #ifdef MMX_COEF
 		}
 #endif
 	} else {
-		EVP_CIPHER_CTX ctx;
+		DES_key_schedule ks1, ks2, ks3;
 		unsigned char TEMP1[sizeof(cur_salt->wrapped_hmac_sha1_key)];
-		int outlen, tmplen;
 		AES_KEY aes_decrypt_key;
 		unsigned char outbuf[8192 + 1];
 		unsigned char outbuf2[4096 + 1];
 		unsigned char iv[20];
-		HMAC_CTX hmacsha1_ctx;
-		int mdlen;
 #ifdef DMG_DEBUG
 		unsigned char *r;
 #endif
@@ -547,27 +539,18 @@ static void hash_plugin_check_hash(int index)
 		for(j = 0; j < SSE_GROUP_SZ_SHA1; ++j) {
 		derived_key = Derived_key[j];
 #endif
-		EVP_CIPHER_CTX_init(&ctx);
-		EVP_DecryptInit_ex(&ctx, EVP_des_ede3_cbc(), NULL, derived_key, cur_salt->iv);
-		if (!EVP_DecryptUpdate(&ctx, TEMP1, &outlen,
-		    cur_salt->encrypted_keyblob, cur_salt->encrypted_keyblob_size)) {
-			EVP_CIPHER_CTX_cleanup(&ctx);
-#ifdef MMX_COEF
-			continue;
-#else
-			return;
-#endif
-		}
-		EVP_DecryptFinal_ex(&ctx, TEMP1 + outlen, &tmplen);
-		EVP_CIPHER_CTX_cleanup(&ctx);
-		outlen += tmplen;
+
+		DES_set_key((DES_cblock*)(derived_key +  0), &ks1);
+		DES_set_key((DES_cblock*)(derived_key +  8), &ks2);
+		DES_set_key((DES_cblock*)(derived_key + 16), &ks3);
+		memcpy(iv, cur_salt->iv, 8);
+		DES_ede3_cbc_encrypt(cur_salt->encrypted_keyblob, TEMP1,
+		                     cur_salt->encrypted_keyblob_size, &ks1, &ks2, &ks3,
+		                     (DES_cblock*)iv, DES_DECRYPT);
+
 		memcpy(aes_key_, TEMP1, 32);
 		memcpy(hmacsha1_key_, TEMP1, 20);
-		HMAC_CTX_init(&hmacsha1_ctx);
-		HMAC_Init_ex(&hmacsha1_ctx, hmacsha1_key_, 20, EVP_sha1(), NULL);
-		HMAC_Update(&hmacsha1_ctx, (void *) &cur_salt->cno, 4);
-		HMAC_Final(&hmacsha1_ctx, iv, (unsigned int *) &mdlen);
-		HMAC_CTX_cleanup(&hmacsha1_ctx);
+		hmac_sha1(hmacsha1_key_, 20, (unsigned char*)&cur_salt->cno, 4, iv, 20);
 		if (cur_salt->encrypted_keyblob_size == 48)
 			AES_set_decrypt_key(aes_key_, 128, &aes_decrypt_key);
 		else
@@ -631,12 +614,7 @@ static void hash_plugin_check_hash(int index)
 		/* Second buffer test. If present, *this* is the very first block of the DMG */
 		if (!cracked[index+j] && cur_salt->scp == 1) {
 			int cno = 0;
-
-			HMAC_CTX_init(&hmacsha1_ctx);
-			HMAC_Init_ex(&hmacsha1_ctx, hmacsha1_key_, 20, EVP_sha1(), NULL);
-			HMAC_Update(&hmacsha1_ctx, (void *) &cno, 4);
-			HMAC_Final(&hmacsha1_ctx, iv, (unsigned int *) &mdlen);
-			HMAC_CTX_cleanup(&hmacsha1_ctx);
+			hmac_sha1(hmacsha1_key_, 20, (unsigned char*)&cno, 4, iv, 20);
 			if (cur_salt->encrypted_keyblob_size == 48)
 				AES_set_decrypt_key(aes_key_, 128, &aes_decrypt_key);
 			else
