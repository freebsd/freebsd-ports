--- src/lmtable.c.orig	2013-06-04 07:42:47 UTC
+++ src/lmtable.c
@@ -470,8 +470,8 @@ void lmtable_mkredux(table_t *tbl, uchar
 /*-------------------------------------------------------------------------*/
 void lmtable_mkhash(uchar_t *pwd, uchar_t *hash) {
   uchar_t key[8];
-  des_key_schedule ks;
-  des_cblock *magic = (des_cblock*)lmmagic;
+  DES_key_schedule ks;
+  DES_cblock *magic = (DES_cblock*)lmmagic;
   
   key[0] = pwd[0];
   key[1] = (pwd[0] << 7) | (pwd[1] >> 1);
@@ -482,7 +482,7 @@ void lmtable_mkhash(uchar_t *pwd, uchar_
   key[6] = (pwd[5] << 2) | (pwd[6] >> 6);
   key[7] = (pwd[6] << 1) ;
 
-  des_set_odd_parity(&key);
-  des_set_key(&key, ks);
-  des_ecb_encrypt(magic, (des_cblock*)hash, ks, DES_ENCRYPT);
+  DES_set_odd_parity(&key);
+  DES_set_key(&key, &ks);
+  DES_ecb_encrypt(magic, (DES_cblock*)hash, &ks, DES_ENCRYPT);
 }
