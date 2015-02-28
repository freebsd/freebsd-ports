--- hydra-smb.c.orig	2014-12-07 15:50:24.000000000 +0100
+++ hydra-smb.c	2015-02-28 12:46:44.362186221 +0100
@@ -176,17 +176,17 @@
   des_key[6] = Get7Bits(key, 42);
   des_key[7] = Get7Bits(key, 49);
 
-  des_set_odd_parity((des_cblock *) des_key);
+  DES_set_odd_parity((DES_cblock *) des_key);
 }
 
 /* Do the DesEncryption */
 void DesEncrypt(unsigned char *clear, unsigned char *key, unsigned char *cipher) {
-  des_cblock des_key;
-  des_key_schedule key_schedule;
+  DES_cblock des_key;
+  DES_key_schedule key_schedule;
 
   MakeKey(key, des_key);
-  des_set_key(&des_key, key_schedule);
-  des_ecb_encrypt((des_cblock *) clear, (des_cblock *) cipher, key_schedule, 1);
+  DES_set_key(&des_key, &key_schedule);
+  DES_ecb_encrypt((DES_cblock *) clear, (DES_cblock *) cipher, &key_schedule, 1);
 }
 
 /*
