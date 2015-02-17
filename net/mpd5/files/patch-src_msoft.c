--- src/msoft.c.orig	2013-06-11 09:00:00 UTC
+++ src/msoft.c
@@ -164,7 +164,7 @@ ChallengeResponse(const u_char *chal, co
 static void
 DesEncrypt(const u_char *clear, u_char *key0, u_char *cypher)
 {
-  des_key_schedule	ks;
+  DES_key_schedule	ks;
   u_char		key[8];
 
 /* Create DES key */
@@ -177,11 +177,11 @@ DesEncrypt(const u_char *clear, u_char *
   key[5] = (key0[4] << 3) | (key0[5] >> 5);
   key[6] = (key0[5] << 2) | (key0[6] >> 6);
   key[7] = key0[6] << 1;
-  des_set_key((des_cblock *) key, ks);
+  DES_set_key((DES_cblock *) key, &ks);
 
 /* Encrypt using key */
 
-  des_ecb_encrypt((des_cblock *) clear, (des_cblock *) cypher, ks, 1);
+  DES_ecb_encrypt((DES_cblock *) clear, (DES_cblock *) cypher, &ks, 1);
 }
 
 /*
