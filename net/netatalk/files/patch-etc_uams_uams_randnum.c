$OpenBSD: patch-etc_uams_uams_randnum_c,v 1.1 2014/04/15 16:12:21 naddy Exp $
--- etc/uams/uams_randnum.c.orig	Tue Jul 23 11:10:55 2013
+++ etc/uams/uams_randnum.c	Tue Apr 15 16:38:15 2014
@@ -55,8 +55,8 @@ char *strchr (), *strrchr ();
 
 #define PASSWDLEN 8
 
-static C_Block		seskey;
-static Key_schedule	seskeysched;
+static DES_cblock	seskey;
+static DES_key_schedule	seskeysched;
 static struct passwd	*randpwd;
 static u_int8_t         randbuf[8];
 
@@ -146,7 +146,7 @@ static int afppasswd(const struct passwd *pwd, 
 {
   u_int8_t key[DES_KEY_SZ*2];
   char buf[MAXPATHLEN + 1], *p;
-  Key_schedule	schedule;
+  DES_key_schedule schedule;
   FILE *fp;
   unsigned int i, j;
   int keyfd = -1, err = 0;
@@ -203,17 +203,17 @@ afppasswd_found:
 	key[j] = (unhex(key[i]) << 4) | unhex(key[i + 1]);
       if (j <= DES_KEY_SZ)
 	memset(key + j, 0, sizeof(key) - j);
-      key_sched((C_Block *) key, schedule);
+      DES_key_sched((DES_cblock *) key, &schedule);
       memset(key, 0, sizeof(key));
 
       if (set) {
 	/* NOTE: this takes advantage of the fact that passwd doesn't
 	 *       get used after this call if it's being set. */
-	ecb_encrypt((C_Block *) passwd, (C_Block *) passwd, schedule,
+	DES_ecb_encrypt((DES_cblock *) passwd, (DES_cblock *) passwd, &schedule,
 		    DES_ENCRYPT);
       } else {
 	/* decrypt the password */
-	ecb_encrypt((C_Block *) p, (C_Block *) p, schedule, DES_DECRYPT);
+	DES_ecb_encrypt((DES_cblock *) p, (DES_cblock *) p, &schedule, DES_DECRYPT);
       }
       memset(&schedule, 0, sizeof(schedule));
   }
@@ -362,10 +362,10 @@ static int randnum_logincont(void *obj, struct passwd 
 
   /* encrypt. this saves a little space by using the fact that
    * des can encrypt in-place without side-effects. */
-  key_sched((C_Block *) seskey, seskeysched);
+  DES_key_sched((DES_cblock *) seskey, &seskeysched);
   memset(seskey, 0, sizeof(seskey));
-  ecb_encrypt((C_Block *) randbuf, (C_Block *) randbuf,
-	       seskeysched, DES_ENCRYPT);
+  DES_ecb_encrypt((DES_cblock *) randbuf, (DES_cblock *) randbuf,
+	       &seskeysched, DES_ENCRYPT);
   memset(&seskeysched, 0, sizeof(seskeysched));
 
   /* test against what the client sent */
@@ -406,10 +406,10 @@ static int rand2num_logincont(void *obj, struct passwd
     seskey[i] <<= 1;
 
   /* encrypt randbuf */
-  key_sched((C_Block *) seskey, seskeysched);
+  DES_key_sched((DES_cblock *) seskey, &seskeysched);
   memset(seskey, 0, sizeof(seskey));
-  ecb_encrypt( (C_Block *) randbuf, (C_Block *) randbuf,
-	       seskeysched, DES_ENCRYPT);
+  DES_ecb_encrypt( (DES_cblock *) randbuf, (DES_cblock *) randbuf,
+	       &seskeysched, DES_ENCRYPT);
 
   /* test against client's reply */
   if (memcmp(randbuf, ibuf, sizeof(randbuf))) { /* != */
@@ -421,8 +421,8 @@ static int rand2num_logincont(void *obj, struct passwd
   memset(randbuf, 0, sizeof(randbuf));
 
   /* encrypt client's challenge and send back */
-  ecb_encrypt( (C_Block *) ibuf, (C_Block *) rbuf,
-	       seskeysched, DES_ENCRYPT);
+  DES_ecb_encrypt( (DES_cblock *) ibuf, (DES_cblock *) rbuf,
+	       &seskeysched, DES_ENCRYPT);
   memset(&seskeysched, 0, sizeof(seskeysched));
   *rbuflen = sizeof(randbuf);
   
@@ -457,15 +457,15 @@ static int randnum_changepw(void *obj, const char *use
       return err;
 
     /* use old passwd to decrypt new passwd */
-    key_sched((C_Block *) seskey, seskeysched);
+    DES_key_sched((DES_cblock *) seskey, &seskeysched);
     ibuf += PASSWDLEN; /* new passwd */
     ibuf[PASSWDLEN] = '\0';
-    ecb_encrypt( (C_Block *) ibuf, (C_Block *) ibuf, seskeysched, DES_DECRYPT);
+    DES_ecb_encrypt( (DES_cblock *) ibuf, (DES_cblock *) ibuf, &seskeysched, DES_DECRYPT);
 
     /* now use new passwd to decrypt old passwd */
-    key_sched((C_Block *) ibuf, seskeysched);
+    DES_key_sched((DES_cblock *) ibuf, &seskeysched);
     ibuf -= PASSWDLEN; /* old passwd */
-    ecb_encrypt((C_Block *) ibuf, (C_Block *) ibuf, seskeysched, DES_DECRYPT);
+    DES_ecb_encrypt((DES_cblock *) ibuf, (DES_cblock *) ibuf, &seskeysched, DES_DECRYPT);
     if (memcmp(seskey, ibuf, sizeof(seskey))) 
 	err = AFPERR_NOTAUTH;
     else if (memcmp(seskey, ibuf + PASSWDLEN, sizeof(seskey)) == 0)
