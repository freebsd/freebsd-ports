--- bin/afppasswd/afppasswd.c.orig	Thu Feb 20 00:04:51 2003
+++ bin/afppasswd/afppasswd.c	Thu Feb 20 00:04:57 2003
@@ -114,7 +114,7 @@
       /* decrypt the password */
       ecb_encrypt((C_Block *) buf, (C_Block *) buf, schedule, DES_DECRYPT);
     }
-    memset(schedule, 0, sizeof(schedule));      
+    memset(&schedule, 0, sizeof(schedule));      
   }
 
   if (newpwd) {
