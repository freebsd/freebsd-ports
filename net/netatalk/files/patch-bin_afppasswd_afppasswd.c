$OpenBSD: patch-bin_afppasswd_afppasswd_c,v 1.4 2014/04/15 16:12:21 naddy Exp $
--- bin/afppasswd/afppasswd.c.orig	Tue Jul 23 11:10:55 2013
+++ bin/afppasswd/afppasswd.c	Tue Apr 15 16:24:33 2014
@@ -70,7 +70,7 @@ static char buf[MAXPATHLEN + 1];
 static void convert_passwd(char *buf, char *newpwd, const int keyfd)
 {
   u_int8_t key[HEXPASSWDLEN];
-  Key_schedule schedule;
+  DES_key_schedule schedule;
   unsigned int i, j;
 
   if (!newpwd) {
@@ -89,14 +89,14 @@ static void convert_passwd(char *buf, char *newpwd, co
       key[j] = (unhex(key[i]) << 4) | unhex(key[i + 1]);
     if (j <= DES_KEY_SZ)
       memset(key + j, 0, sizeof(key) - j);
-    key_sched((C_Block *) key, schedule);
+    DES_key_sched((DES_cblock *) key, &schedule);
     memset(key, 0, sizeof(key));   
     if (newpwd) {
-	ecb_encrypt((C_Block *) newpwd, (C_Block *) newpwd, schedule,
+	DES_ecb_encrypt((DES_cblock *) newpwd, (DES_cblock *) newpwd, &schedule,
 		    DES_ENCRYPT);
     } else {
       /* decrypt the password */
-      ecb_encrypt((C_Block *) buf, (C_Block *) buf, schedule, DES_DECRYPT);
+      DES_ecb_encrypt((DES_cblock *) buf, (DES_cblock *) buf, &schedule, DES_DECRYPT);
     }
     memset(&schedule, 0, sizeof(schedule));      
   }
