--- hydra-snmp.c.orig	2014-12-07 15:50:24.000000000 +0100
+++ hydra-snmp.c	2015-02-28 12:52:49.999228359 +0100
@@ -335,13 +335,13 @@
       // xor initVect with salt  
       for (i = 0; i < 8; i++)
         initVect[i] ^= privacy_params[i];
-      des_key_sched((C_Block *) key, symcbc);
-      des_ncbc_encrypt(snmpv3_get2 + 2, buf, sizeof(snmpv3_get2) - 2, symcbc, (C_Block *) (initVect), DES_ENCRYPT);
+      DES_key_sched((DES_cblock *) key, &symcbc);
+      DES_ncbc_encrypt(snmpv3_get2 + 2, buf, sizeof(snmpv3_get2) - 2, &symcbc, (DES_cblock *) (initVect), DES_ENCRYPT);
 
 #endif
 
 /*  for (i = 0; i <= sizeof(snmpv3_get2) - 8; i += 8) {  
-    des_ncbc_encrypt(snmpv3_get2 + i, buf + i, 8, (C_Block*)(initVect), DES_ENCRYPT);
+    DES_ncbc_encrypt(snmpv3_get2 + i, buf + i, 8, (DES_cblock*)(initVect), DES_ENCRYPT);
   }  
   // last part of buffer
   if (buffer_len % 8) {  
@@ -351,7 +351,7 @@
     memset(tmp_buf, 0, 8);  
     for (unsigned int l = start; l < buffer_len; l++)  
       *tmp_buf_ptr++ = buffer[l];  
-    des_ncbc_encrypt(tmp_buf, buf + start, 1, symcbc, (C_Block*)(initVect), DES_ENCRYPT);
+    DES_ncbc_encrypt(tmp_buf, buf + start, 1, &symcbc, (DES_cblock*)(initVect), DES_ENCRYPT);
     *out_buffer_len = buffer_len + 8 - (buffer_len % 8);  
   } else  
     *out_buffer_len = buffer_len;  
