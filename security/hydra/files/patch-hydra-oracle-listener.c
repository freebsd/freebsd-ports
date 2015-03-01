--- hydra-oracle-listener.c.orig	2014-12-07 15:50:20.000000000 +0100
+++ hydra-oracle-listener.c	2015-02-28 12:55:33.285896567 +0100
@@ -106,7 +106,7 @@
 int ora_descrypt(unsigned char **rs, unsigned char *result, int siz) {
   int i = 0;
   char lastkey[8];
-  des_key_schedule ks1;
+  DES_key_schedule ks1;
   unsigned char key1[8] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF };
   unsigned char ivec1[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   unsigned char *desresult;
@@ -116,17 +116,17 @@
     hydra_report(stderr, "[ERROR] Can't allocate memory\n");
     return 1;
   }
-  des_key_sched((C_Block *) key1, ks1);
-  des_ncbc_encrypt(result, desresult, siz, ks1, &ivec1, DES_ENCRYPT);
+  DES_key_sched((DES_cblock *) key1, &ks1);
+  DES_ncbc_encrypt(result, desresult, siz, &ks1, &ivec1, DES_ENCRYPT);
 
   for (i = 0; i < 8; i++) {
     lastkey[i] = desresult[siz - 8 + i];
   }
 
-  des_key_sched((C_Block *) lastkey, ks1);
+  DES_key_sched((DES_cblock *) lastkey, &ks1);
   memset(desresult, 0, siz);
   memset(ivec1, 0, sizeof(ivec1));
-  des_ncbc_encrypt(result, desresult, siz, ks1, &ivec1, DES_ENCRYPT);
+  DES_ncbc_encrypt(result, desresult, siz, &ks1, &ivec1, DES_ENCRYPT);
 
   if ((*rs = malloc(siz)) == NULL) {
     hydra_report(stderr, "[ERROR] Can't allocate memory\n");
