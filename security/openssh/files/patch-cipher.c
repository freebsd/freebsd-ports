--- cipher.c.orig	Fri Mar  8 21:38:18 2002
+++ cipher.c	Tue Feb 19 05:26:43 2002
@@ -41,8 +41,6 @@
 #include "log.h"
 #include "cipher.h"
 
-#define EVP_CIPHER_CTX_get_app_data(e)          ((e)->app_data)
- 
 #include <openssl/md5.h>
 #include "rijndael.h"
 
@@ -198,8 +196,20 @@
 	type = (*cipher->evptype)();
 
 	EVP_CIPHER_CTX_init(&cc->evp);
-	EVP_CipherInit(&cc->evp, type, (u_char *)key, (u_char *)iv,
-	    (encrypt == CIPHER_ENCRYPT));
+	if (EVP_CipherInit(&cc->evp, type, NULL, (u_char *)iv,
+	    (encrypt == CIPHER_ENCRYPT)) == 0)
+		fatal("cipher_init: EVP_CipherInit failed for %s",
+		    cipher->name);
+	klen = EVP_CIPHER_CTX_key_length(&cc->evp);
+	if (klen > 0 && keylen != klen) {
+		debug("cipher_init: set keylen (%d -> %d)", klen, keylen);
+		if (EVP_CIPHER_CTX_set_key_length(&cc->evp, keylen) == 0)
+			fatal("cipher_init: set keylen failed (%d -> %d)",
+			    klen, keylen);
+	}
+	if (EVP_CipherInit(&cc->evp, NULL, (u_char *)key, NULL, -1) == 0)
+		fatal("cipher_init: EVP_CipherInit: set key failed for %s",
+		    cipher->name);
 }
 
 void
@@ -207,13 +217,15 @@
 {
 	if (len % cc->cipher->block_size)
 		fatal("cipher_encrypt: bad plaintext length %d", len);
-	EVP_Cipher(&cc->evp, dest, (u_char *)src, len);
+	if (EVP_Cipher(&cc->evp, dest, (u_char *)src, len) == 0)
+		fatal("evp_crypt: EVP_Cipher failed");
 }
 
 void
 cipher_cleanup(CipherContext *cc)
 {
-	EVP_CIPHER_CTX_cleanup(&cc->evp);
+	if (EVP_CIPHER_CTX_cleanup(&cc->evp) == 0)
+		error("cipher_cleanup: EVP_CIPHER_CTX_cleanup failed");
 }
 
 /*
@@ -284,9 +296,14 @@
 	EVP_CIPHER_CTX_init(&c->k1);
 	EVP_CIPHER_CTX_init(&c->k2);
 	EVP_CIPHER_CTX_init(&c->k3);
-	EVP_CipherInit(&c->k1, EVP_des_cbc(), k1, NULL, enc);
-	EVP_CipherInit(&c->k2, EVP_des_cbc(), k2, NULL, !enc);
-	EVP_CipherInit(&c->k3, EVP_des_cbc(), k3, NULL, enc);
+	if (EVP_CipherInit(&c->k1, EVP_des_cbc(), k1, NULL, enc) == 0 ||
+	    EVP_CipherInit(&c->k2, EVP_des_cbc(), k2, NULL, !enc) == 0 ||
+	    EVP_CipherInit(&c->k3, EVP_des_cbc(), k3, NULL, enc) == 0) {
+		memset(c, 0, sizeof(*c));
+		xfree(c);
+		EVP_CIPHER_CTX_set_app_data(ctx, NULL);
+		return (0);
+	}
 	return (1);
 }
 static int
@@ -298,9 +315,10 @@
 		error("ssh1_3des_cbc: no context");
 		return (0);
 	}
-	EVP_Cipher(&c->k1, dest, (u_char *)src, len);
-	EVP_Cipher(&c->k2, dest, dest, len);
-	EVP_Cipher(&c->k3, dest, dest, len);
+	if (EVP_Cipher(&c->k1, dest, (u_char *)src, len) == 0 ||
+	    EVP_Cipher(&c->k2, dest, dest, len) == 0 ||
+	    EVP_Cipher(&c->k3, dest, dest, len) == 0)
+		return (0);
 	return (1);
 }
 static int
@@ -328,6 +346,7 @@
 	ssh1_3des.init = ssh1_3des_init;
 	ssh1_3des.cleanup = ssh1_3des_cleanup;
 	ssh1_3des.do_cipher = ssh1_3des_cbc;
+	ssh1_3des.flags = EVP_CIPH_CBC_MODE | EVP_CIPH_VARIABLE_LENGTH;
 	return (&ssh1_3des);
 }
 
@@ -475,5 +494,7 @@
 	rijndal_cbc.init = ssh_rijndael_init;
 	rijndal_cbc.cleanup = ssh_rijndael_cleanup;
 	rijndal_cbc.do_cipher = ssh_rijndael_cbc;
+	rijndal_cbc.flags = EVP_CIPH_CBC_MODE | EVP_CIPH_VARIABLE_LENGTH |
+	    EVP_CIPH_ALWAYS_CALL_INIT;
 	return (&rijndal_cbc);
 }
