--- ntlm/ntlmdes.c.orig	2010-08-08 15:45:56 UTC
+++ ntlm/ntlmdes.c
@@ -30,10 +30,10 @@
 #include "ntlm.h"
 
 static void
-lm_deshash (void *result, const_des_cblock *iv, const void *secret)
+lm_deshash (void *result, const_DES_cblock *iv, const void *secret)
 {
-  des_cblock key;
-  des_key_schedule ks;
+  DES_cblock key;
+  DES_key_schedule ks;
   unsigned char key_56[8];
   size_t len;
 
@@ -85,7 +85,7 @@ lm_uccpy (char *dst, size_t dstlen, cons
 void
 lm_hash_password (unsigned char *hash, const char *pass)
 {
-  static const_des_cblock iv = { 0x4B, 0x47, 0x53, 0x21,
+  static const_DES_cblock iv = { 0x4B, 0x47, 0x53, 0x21,
                                  0x40, 0x23, 0x24, 0x25 };
   char lmpass[14];
 
@@ -137,7 +137,7 @@ ntlm_responses (unsigned char *lm_resp, 
 		const unsigned char *challenge, const char *secret)
 {
   unsigned char hash[21];
-  des_cblock nonce;
+  DES_cblock nonce;
 
   memcpy (&nonce, challenge, sizeof nonce);
 
