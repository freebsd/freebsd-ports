--- etc/uams/uams_randnum.c.orig	Thu Feb 20 00:05:48 2003
+++ etc/uams/uams_randnum.c	Thu Feb 20 00:07:56 2003
@@ -217,7 +217,7 @@
 	/* decrypt the password */
 	ecb_encrypt((C_Block *) p, (C_Block *) p, schedule, DES_DECRYPT);
       }
-      memset(schedule, 0, sizeof(schedule));
+      memset(&schedule, 0, sizeof(schedule));
   }
 
   if (set) {
@@ -383,7 +383,7 @@
   memset(seskey, 0, sizeof(seskey));
   ecb_encrypt((C_Block *) randbuf, (C_Block *) randbuf,
 	       seskeysched, DES_ENCRYPT);
-  memset(seskeysched, 0, sizeof(seskeysched));
+  memset(&seskeysched, 0, sizeof(seskeysched));
 
   /* test against what the client sent */
   if (memcmp( randbuf, ibuf, sizeof(randbuf) )) { /* != */
@@ -431,7 +431,7 @@
   /* test against client's reply */
   if (memcmp(randbuf, ibuf, sizeof(randbuf))) { /* != */
     memset(randbuf, 0, sizeof(randbuf));
-    memset(seskeysched, 0, sizeof(seskeysched));
+    memset(&seskeysched, 0, sizeof(seskeysched));
     return AFPERR_NOTAUTH;
   }
   ibuf += sizeof(randbuf);
@@ -440,7 +440,7 @@
   /* encrypt client's challenge and send back */
   ecb_encrypt( (C_Block *) ibuf, (C_Block *) rbuf,
 	       seskeysched, DES_ENCRYPT);
-  memset(seskeysched, 0, sizeof(seskeysched));
+  memset(&seskeysched, 0, sizeof(seskeysched));
   *rbuflen = sizeof(randbuf);
   
   *uam_pwd = randpwd;
@@ -495,7 +495,7 @@
       err = randpass(pwd, passwdfile, ibuf + PASSWDLEN, sizeof(seskey), 1);
 
     /* zero out some fields */
-    memset(seskeysched, 0, sizeof(seskeysched));
+    memset(&seskeysched, 0, sizeof(seskeysched));
     memset(seskey, 0, sizeof(seskey));
     memset(ibuf, 0, sizeof(seskey)); /* old passwd */
     memset(ibuf + PASSWDLEN, 0, sizeof(seskey)); /* new passwd */
