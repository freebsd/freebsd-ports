--- crypto.c.orig	2004-06-14 11:55:41.000000000 +0200
+++ crypto.c	2015-02-28 13:23:13.232107608 +0100
@@ -100,7 +100,7 @@
 
 /* Hmm, the function prototypes for des are really dumb */
 #ifdef __OpenBSD__
-#define DC	(des_cblock *)
+#define DC	(DES_cblock *)
 #else
 #define DC	(void *)
 #endif
@@ -109,8 +109,8 @@
 des1_init(struct keystate *ks, u_int8_t *key, u_int16_t len)
 {
 	/* des_set_key returns -1 for parity problems, and -2 for weak keys */
-	des_set_odd_parity(DC key);
-	switch (des_set_key(DC key, ks->ks_des[0])) {
+	DES_set_odd_parity(DC key);
+	switch (DES_set_key(DC key, &ks->ks_des[0])) {
 	case -2:
 		return EWEAKKEY;
 	default:
@@ -121,14 +121,14 @@
 void
 des1_encrypt(struct keystate *ks, u_int8_t *d, u_int16_t len)
 {
-	des_cbc_encrypt(DC d, DC d, len, ks->ks_des[0], DC ks->riv,
+	DES_cbc_encrypt(DC d, DC d, len, &ks->ks_des[0], DC ks->riv,
 	    DES_ENCRYPT);
 }
 
 void
 des1_decrypt(struct keystate *ks, u_int8_t *d, u_int16_t len)
 {
-	des_cbc_encrypt(DC d, DC d, len, ks->ks_des[0], DC ks->riv,
+	DES_cbc_encrypt(DC d, DC d, len, &ks->ks_des[0], DC ks->riv,
 	    DES_DECRYPT);
 }
 
@@ -136,14 +136,14 @@
 enum cryptoerr
 des3_init(struct keystate *ks, u_int8_t *key, u_int16_t len)
 {
-	des_set_odd_parity(DC key);
-	des_set_odd_parity(DC(key + 8));
-	des_set_odd_parity(DC(key + 16));
+	DES_set_odd_parity(DC key);
+	DES_set_odd_parity(DC(key + 8));
+	DES_set_odd_parity(DC(key + 16));
 
 	/* As of the draft Tripe-DES does not check for weak keys */
-	des_set_key(DC key, ks->ks_des[0]);
-	des_set_key(DC(key + 8), ks->ks_des[1]);
-	des_set_key(DC(key + 16), ks->ks_des[2]);
+	DES_set_key(DC key, &ks->ks_des[0]);
+	DES_set_key(DC(key + 8), &ks->ks_des[1]);
+	DES_set_key(DC(key + 16), &ks->ks_des[2]);
 
 	return EOKAY;
 }
@@ -154,8 +154,8 @@
 	u_int8_t        iv[MAXBLK];
 
 	memcpy(iv, ks->riv, ks->xf->blocksize);
-	des_ede3_cbc_encrypt(DC data, DC data, len, ks->ks_des[0],
-	    ks->ks_des[1], ks->ks_des[2], DC iv, DES_ENCRYPT);
+	DES_ede3_cbc_encrypt(DC data, DC data, len, &ks->ks_des[0],
+	    &ks->ks_des[1], &ks->ks_des[2], DC iv, DES_ENCRYPT);
 }
 
 void
@@ -164,8 +164,8 @@
 	u_int8_t        iv[MAXBLK];
 
 	memcpy(iv, ks->riv, ks->xf->blocksize);
-	des_ede3_cbc_encrypt(DC data, DC data, len, ks->ks_des[0],
-	    ks->ks_des[1], ks->ks_des[2], DC iv, DES_DECRYPT);
+	DES_ede3_cbc_encrypt(DC data, DC data, len, &ks->ks_des[0],
+	    &ks->ks_des[1], &ks->ks_des[2], DC iv, DES_DECRYPT);
 }
 #undef DC
 #endif				/* USE_TRIPLEDES */
