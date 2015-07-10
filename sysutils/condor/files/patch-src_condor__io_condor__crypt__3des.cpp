--- src/condor_io/condor_crypt_3des.cpp.orig	2015-04-07 15:10:11 UTC
+++ src/condor_io/condor_crypt_3des.cpp
@@ -35,9 +35,9 @@ Condor_Crypt_3des :: Condor_Crypt_3des(c
 	unsigned char * keyData = k.getPaddedKeyData(24);
 	ASSERT(keyData);
 
-    des_set_key((des_cblock *)  keyData    , keySchedule1_);
-    des_set_key((des_cblock *) (keyData+8) , keySchedule2_);
-    des_set_key((des_cblock *) (keyData+16), keySchedule3_);
+    DES_set_key((DES_cblock *)  keyData    , &keySchedule1_);
+    DES_set_key((DES_cblock *) (keyData+8) , &keySchedule2_);
+    DES_set_key((DES_cblock *) (keyData+16), &keySchedule3_);
 
     // initialize ivsec
     resetState();
@@ -71,9 +71,9 @@ bool Condor_Crypt_3des :: encrypt(unsign
     output = (unsigned char *) malloc(input_len);
 
     if (output) {
-        des_ede3_cfb64_encrypt(input, output, output_len,
-                               keySchedule1_, keySchedule2_, keySchedule3_,
-                               (des_cblock *)ivec_, &num_, DES_ENCRYPT);
+        DES_ede3_cfb64_encrypt(input, output, output_len,
+                               &keySchedule1_, &keySchedule2_, &keySchedule3_,
+                               (DES_cblock *)ivec_, &num_, DES_ENCRYPT);
         return true;   
     }
     else {
@@ -95,9 +95,9 @@ bool Condor_Crypt_3des :: decrypt(unsign
     if (output) {
         output_len = input_len;
 
-        des_ede3_cfb64_encrypt(input, output, output_len,
-                               keySchedule1_, keySchedule2_, keySchedule3_,
-                               (des_cblock *)ivec_, &num_, DES_DECRYPT);
+        DES_ede3_cfb64_encrypt(input, output, output_len,
+                               &keySchedule1_, &keySchedule2_, &keySchedule3_,
+                               (DES_cblock *)ivec_, &num_, DES_DECRYPT);
         
         return true;           // Should be changed
     }
