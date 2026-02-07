$OpenBSD: patch-sshcrypto_c,v 1.3 2015/05/29 15:57:29 jca Exp $
--- sshcrypto.c.orig	Tue Nov 28 22:23:28 2000
+++ sshcrypto.c	Fri May 29 17:56:22 2015
@@ -15,7 +15,9 @@
 #include <sys/types.h>
 #include <openssl/ssl.h>
 
+#include <openssl/des.h>
 #include <err.h>
+#include <openssl/blowfish.h>
 #include <stdio.h>
 #include <stdlib.h>
 
@@ -27,8 +29,8 @@ struct blowfish_state {
 };
 
 struct des3_state {
-	des_key_schedule	k1, k2, k3;
-	des_cblock		iv1, iv2, iv3;
+	DES_key_schedule	k1, k2, k3;
+	DES_cblock		iv1, iv2, iv3;
 };
 
 void
@@ -153,13 +155,13 @@ des3_init(u_char *sesskey, int len)
 	if ((state = malloc(sizeof(*state))) == NULL)
 		err(1, "malloc");
 
-	des_set_key((void *)sesskey, state->k1);
-	des_set_key((void *)(sesskey + 8), state->k2);
+	DES_set_key((void *)sesskey, &state->k1);
+	DES_set_key((void *)(sesskey + 8), &state->k2);
 
 	if (len <= 16)
-		des_set_key((void *)sesskey, state->k3);
+		DES_set_key((void *)sesskey, &state->k3);
 	else
-		des_set_key((void *)(sesskey + 16), state->k3);
+		DES_set_key((void *)(sesskey + 16), &state->k3);
 	
 	memset(state->iv1, 0, 8);
 	memset(state->iv2, 0, 8);
@@ -175,9 +177,9 @@ des3_encrypt(u_char *src, u_char *dst, int len, void *
 	estate = (struct des3_state *)state;
 	memcpy(estate->iv1, estate->iv2, 8);
 	
-	des_ncbc_encrypt(src, dst, len, estate->k1, &estate->iv1, DES_ENCRYPT);
-	des_ncbc_encrypt(dst, dst, len, estate->k2, &estate->iv2, DES_DECRYPT);
-	des_ncbc_encrypt(dst, dst, len, estate->k3, &estate->iv3, DES_ENCRYPT);
+	DES_ncbc_encrypt(src, dst, len, &estate->k1, &estate->iv1, DES_ENCRYPT);
+	DES_ncbc_encrypt(dst, dst, len, &estate->k2, &estate->iv2, DES_DECRYPT);
+	DES_ncbc_encrypt(dst, dst, len, &estate->k3, &estate->iv3, DES_ENCRYPT);
 }
 
 void
@@ -188,7 +190,7 @@ des3_decrypt(u_char *src, u_char *dst, int len, void *
 	dstate = (struct des3_state *)state;
 	memcpy(dstate->iv1, dstate->iv2, 8);
 	
-	des_ncbc_encrypt(src, dst, len, dstate->k3, &dstate->iv3, DES_DECRYPT);
-	des_ncbc_encrypt(dst, dst, len, dstate->k2, &dstate->iv2, DES_ENCRYPT);
-	des_ncbc_encrypt(dst, dst, len, dstate->k1, &dstate->iv1, DES_DECRYPT);
+	DES_ncbc_encrypt(src, dst, len, &dstate->k3, &dstate->iv3, DES_DECRYPT);
+	DES_ncbc_encrypt(dst, dst, len, &dstate->k2, &dstate->iv2, DES_ENCRYPT);
+	DES_ncbc_encrypt(dst, dst, len, &dstate->k1, &dstate->iv1, DES_DECRYPT);
 }
