--- chntpw.c.orig	2020-05-05 11:29:42 UTC
+++ chntpw.c
@@ -155,7 +155,7 @@ void str_to_key(unsigned char *str,unsigned char *key)
 	for (i=0;i<8;i++) {
 		key[i] = (key[i]<<1);
 	}
-	DES_set_odd_parity((des_cblock *)key);
+	DES_set_odd_parity((DES_cblock *)key);
 }
 
 /*
@@ -200,16 +200,16 @@ void sid_to_key2(uint32_t sid,unsigned char deskey[8])
 
 void E1(uchar *k, uchar *d, uchar *out)
 {
-  des_key_schedule ks;
-  des_cblock deskey;
+  DES_key_schedule ks;
+  DES_cblock deskey;
 
   str_to_key(k,(uchar *)deskey);
 #ifdef __FreeBSD__
-  des_set_key(&deskey,ks);
+  DES_set_key(&deskey,&ks);
 #else /* __FreeBsd__ */
-  des_set_key((des_cblock *)deskey,ks);
+  DES_set_key((DES_cblock *)deskey,&ks);
 #endif /* __FreeBsd__ */
-  des_ecb_encrypt((des_cblock *)d,(des_cblock *)out, ks, DES_ENCRYPT);
+  DES_ecb_encrypt((DES_cblock *)d,(DES_cblock *)out, &ks, DES_ENCRYPT);
 }
 
 #endif   /* DOCRYPTO */
@@ -343,8 +343,8 @@ char *change_pw(char *buf, int rid, int vlen, int stat
    int i;
    char md4[32],lanman[32];
    char newunipw[34], despw[20], newlanpw[16], newlandes[20];
-   des_key_schedule ks1, ks2;
-   des_cblock deskey1, deskey2;
+   DES_key_schedule ks1, ks2;
+   DES_cblock deskey1, deskey2;
    MD4_CTX context;
    unsigned char digest[16];
    uchar x1[] = {0x4B,0x47,0x53,0x21,0x40,0x23,0x24,0x25};
@@ -462,21 +462,21 @@ char *change_pw(char *buf, int rid, int vlen, int stat
 #ifdef DOCRYPTO
    /* Get the two decrpt keys. */
    sid_to_key1(rid,(unsigned char *)deskey1);
-   des_set_key((des_cblock *)deskey1,ks1);
+   DES_set_key((DES_cblock *)deskey1,&ks1);
    sid_to_key2(rid,(unsigned char *)deskey2);
-   des_set_key((des_cblock *)deskey2,ks2);
+   DES_set_key((DES_cblock *)deskey2,&ks2);
    
    /* Decrypt the NT md4 password hash as two 8 byte blocks. */
-   des_ecb_encrypt((des_cblock *)(vp+ntpw_offs ),
-		   (des_cblock *)md4, ks1, DES_DECRYPT);
-   des_ecb_encrypt((des_cblock *)(vp+ntpw_offs + 8),
-		   (des_cblock *)&md4[8], ks2, DES_DECRYPT);
+   DES_ecb_encrypt((DES_cblock *)(vp+ntpw_offs ),
+		   (DES_cblock *)md4, &ks1, DES_DECRYPT);
+   DES_ecb_encrypt((DES_cblock *)(vp+ntpw_offs + 8),
+		   (DES_cblock *)&md4[8], &ks2, DES_DECRYPT);
 
    /* Decrypt the lanman password hash as two 8 byte blocks. */
-   des_ecb_encrypt((des_cblock *)(vp+lmpw_offs),
-		   (des_cblock *)lanman, ks1, DES_DECRYPT);
-   des_ecb_encrypt((des_cblock *)(vp+lmpw_offs + 8),
-		   (des_cblock *)&lanman[8], ks2, DES_DECRYPT);
+   DES_ecb_encrypt((DES_cblock *)(vp+lmpw_offs),
+		   (DES_cblock *)lanman, &ks1, DES_DECRYPT);
+   DES_ecb_encrypt((DES_cblock *)(vp+lmpw_offs + 8),
+		   (DES_cblock *)&lanman[8], &ks2, DES_DECRYPT);
       
    if (gverbose) {
      hexprnt("MD4 hash     : ",(unsigned char *)md4,16);
@@ -556,15 +556,15 @@ char *change_pw(char *buf, int rid, int vlen, int stat
      if (gverbose) hexprnt("NEW LANMAN hash : ",(unsigned char *)lanman,16);
      
      /* Encrypt the NT md4 password hash as two 8 byte blocks. */
-     des_ecb_encrypt((des_cblock *)digest,
-		     (des_cblock *)despw, ks1, DES_ENCRYPT);
-     des_ecb_encrypt((des_cblock *)(digest+8),
-		     (des_cblock *)&despw[8], ks2, DES_ENCRYPT);
+     DES_ecb_encrypt((DES_cblock *)digest,
+		     (DES_cblock *)despw, &ks1, DES_ENCRYPT);
+     DES_ecb_encrypt((DES_cblock *)digest, 
+		     (DES_cblock *)&despw[8], &ks2, DES_ENCRYPT);
      
-     des_ecb_encrypt((des_cblock *)lanman,
-		     (des_cblock *)newlandes, ks1, DES_ENCRYPT);
-     des_ecb_encrypt((des_cblock *)(lanman+8),
-		     (des_cblock *)&newlandes[8], ks2, DES_ENCRYPT);
+     DES_ecb_encrypt((DES_cblock *)lanman,
+		     (DES_cblock *)newlandes, &ks1, DES_ENCRYPT);
+     DES_ecb_encrypt((DES_cblock *)(lanman+8),
+		     (DES_cblock *)&newlandes[8], &ks2, DES_ENCRYPT);
      
      if (gverbose) {
        hexprnt("NEW DES crypt   : ",(unsigned char *)despw,16);
