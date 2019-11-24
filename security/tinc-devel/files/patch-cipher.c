--- src/openssl/cipher.c.orig	2018-10-07 11:43:07 UTC
+++ src/openssl/cipher.c
@@ -189,7 +189,7 @@ bool cipher_decrypt(cipher_t *cipher, const void *inda
 	} else {
 		int len;
 
-		if(EVP_EncryptUpdate(cipher->ctx, outdata, &len, indata, inlen)) {
+		if(EVP_DecryptUpdate(cipher->ctx, outdata, &len, indata, inlen)) {
 			if(outlen) {
 				*outlen = len;
 			}
