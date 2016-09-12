--- auth_priv.cpp.orig	2016-04-15 19:57:59 UTC
+++ auth_priv.cpp
@@ -89,34 +89,34 @@ typedef MD5_CTX               MD5HashSta
 #define MD5_PROCESS(s, p, l)  MD5_Update(s, p, l)
 #define MD5_DONE(s, k)        MD5_Final(k, s)
 
-typedef des_key_schedule      DESCBCType;
+typedef DES_key_schedule      DESCBCType;
 #define DES_CBC_START_ENCRYPT(c, iv, k, kl, r, s) \
-                 if (des_key_sched((C_Block*)(k), s) < 0) \
+                 if (DES_key_sched((DES_cblock*)(k), &s) < 0) \
                  { \
 		   debugprintf(0, "Starting DES encryption failed."); \
 		   return SNMPv3_USM_ERROR; \
                  }
 #define DES_CBC_START_DECRYPT(c, iv, k, kl, r, s) \
-                 if (des_key_sched((C_Block*)(k), s) < 0) \
+                 if (DES_key_sched((DES_cblock*)(k), &s) < 0) \
                  { \
 		   debugprintf(0, "Starting DES decryption failed."); \
 		   return SNMPv3_USM_ERROR; \
                  }
 
 #define DES_CBC_ENCRYPT(pt, ct, s, iv, l) \
-                        des_ncbc_encrypt(pt, ct, l, \
-                                         s, (C_Block*)(iv), DES_ENCRYPT)
+                        DES_ncbc_encrypt(pt, ct, l, \
+                                         &s, (DES_cblock*)(iv), DES_ENCRYPT)
 #define DES_CBC_DECRYPT(ct, pt, s, iv, l) \
-                        des_ncbc_encrypt(ct, pt, l, \
-                                         s, (C_Block*)(iv), DES_DECRYPT)
+                        DES_ncbc_encrypt(ct, pt, l, \
+                                         &s, (DES_cblock*)(iv), DES_DECRYPT)
 
 #define DES_EDE3_CBC_ENCRYPT(pt, ct, l, k1, k2, k3, iv) \
-               des_ede3_cbc_encrypt(pt, ct, l, \
-                                    k1, k2, k3, (C_Block*)(iv), DES_ENCRYPT)
+               DES_ede3_cbc_encrypt(pt, ct, l, \
+                                    k1, k2, k3, (DES_cblock*)(iv), DES_ENCRYPT)
 
 #define DES_EDE3_CBC_DECRYPT(ct, pt, l, k1, k2, k3, iv) \
-               des_ede3_cbc_encrypt(ct, pt, l, \
-                                    k1, k2, k3, (C_Block*)(iv), DES_DECRYPT)
+               DES_ede3_cbc_encrypt(ct, pt, l, \
+                                    k1, k2, k3, (DES_cblock*)(iv), DES_DECRYPT)
 
 #define DES_MEMSET(s, c, l)   memset(&(s), c, l)
 
@@ -182,12 +182,12 @@ typedef MD5_CTX               MD5HashSta
 #define MD5_DONE(s, k)        MD5Final(k, s)
 
 #define DES_EDE3_CBC_ENCRYPT(pt, ct, l, k1, k2, k3, iv) \
-               des_ede3_cbc_encrypt((C_Block*)(pt), (C_Block*)(ct), l, \
-                                    k1, k2, k3, (C_Block*)(iv), DES_ENCRYPT)
+               DES_ede3_cbc_encrypt((DES_cblock*)(pt), (DES_cblock*)(ct), l, \
+                                    k1, k2, k3, (DES_cblock*)(iv), DES_ENCRYPT)
 
 #define DES_EDE3_CBC_DECRYPT(ct, pt, l, k1, k2, k3, iv) \
-               des_ede3_cbc_encrypt((C_Block*)(ct), (C_Block*)(pt), l, \
-                                    k1, k2, k3, (C_Block*)(iv), DES_DECRYPT)
+               DES_ede3_cbc_encrypt((DES_cblock*)(ct), (DES_cblock*)(pt), l, \
+                                    k1, k2, k3, (DES_cblock*)(iv), DES_DECRYPT)
 
 #ifdef RSAEURO
 
@@ -205,26 +205,26 @@ typedef DES_CBC_CTX           DESCBCType
 
 #else // RSAEURO
 
-typedef des_key_schedule      DESCBCType;
+typedef DES_key_schedule      DESCBCType;
 #define DES_CBC_START_ENCRYPT(c, iv, k, kl, r, s) \
-                 if (des_key_sched((C_Block*)(k), s) < 0) \
+                 if (DES_key_sched((DES_cblock*)(k), &s) < 0) \
                  { \
 		   debugprintf(0, "Starting DES encryption failed."); \
 		   return SNMPv3_USM_ERROR; \
                  }
 #define DES_CBC_START_DECRYPT(c, iv, k, kl, r, s) \
-                 if (des_key_sched((C_Block*)(k), s) < 0) \
+                 if (DES_key_sched((DES_cblock*)(k), &s) < 0) \
                  { \
 		   debugprintf(0, "Starting DES decryption failed."); \
 		   return SNMPv3_USM_ERROR; \
                  }
 
 #define DES_CBC_ENCRYPT(pt, ct, s, iv, l) \
-                        des_ncbc_encrypt((C_Block*)(pt), (C_Block*)(ct), l, \
-                                         s, (C_Block*)(iv), DES_ENCRYPT)
+                        DES_ncbc_encrypt((DES_cblock*)(pt), (DES_cblock*)(ct), l, \
+                                         &s, (DES_cblock*)(iv), DES_ENCRYPT)
 #define DES_CBC_DECRYPT(ct, pt, s, iv, l) \
-                        des_ncbc_encrypt((C_Block*)(ct), (C_Block*)(pt), l, \
-                                         s, (C_Block*)(iv), DES_DECRYPT)
+                        DES_ncbc_encrypt((DES_cblock*)(ct), (DES_cblock*)(pt), l, \
+                                         &s, (DES_cblock*)(iv), DES_DECRYPT)
 #define DES_MEMSET(s, c, l)   memset(&(s), c, l)
 
 /* -- END: Defines for libdes -- */
@@ -1939,9 +1939,9 @@ Priv3DES_EDE::encrypt(const unsigned cha
 #else
   DESCBCType ks1, ks2, ks3;
 
-  if ((des_key_sched((C_Block*)(key),     ks1) < 0) ||
-      (des_key_sched((C_Block*)(key +8),  ks2) < 0) ||
-      (des_key_sched((C_Block*)(key +16), ks3) < 0))
+  if ((DES_key_sched((DES_cblock*)(key),     &ks1) < 0) ||
+      (DES_key_sched((DES_cblock*)(key +8),  &ks2) < 0) ||
+      (DES_key_sched((DES_cblock*)(key +16), &ks3) < 0))
   {
       debugprintf(0, "Starting 3DES-EDE encryption failed.");
       return SNMPv3_USM_ERROR;
@@ -2028,9 +2028,9 @@ Priv3DES_EDE::decrypt(const unsigned cha
 #else
   DESCBCType ks1, ks2, ks3;
 
-  if ((des_key_sched((C_Block*)(key),     ks1) < 0) ||
-      (des_key_sched((C_Block*)(key+8),  ks2) < 0) ||
-      (des_key_sched((C_Block*)(key+16), ks3) < 0))
+  if ((DES_key_sched((C_Block*)(key),    &ks1) < 0) ||
+      (DES_key_sched((C_Block*)(key+8),  &ks2) < 0) ||
+      (DES_key_sched((C_Block*)(key+16), &ks3) < 0))
     {
       debugprintf(0, "Starting 3DES-EDE decryption failed.");
       return SNMPv3_USM_ERROR;
