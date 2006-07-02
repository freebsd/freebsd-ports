--- mdpop3d.c.orig	Tue Feb 27 00:12:50 2001
+++ mdpop3d.c	Sun Jul  2 10:31:40 2006
@@ -67,8 +67,8 @@
 #ifdef USE_APOP
 # error APOP requires PAM
 #endif
-#include <shadow.h>
-#include <crypt.h>
+#include <pwd.h>
+#include <unistd.h>
 #endif
 
 static const char *rhost; /* = NULL; remote host/addr for logging */
@@ -258,7 +258,7 @@
 }
 
 static void info() {
-  putline(OK "maildir: %d message(s) %ld octet(s)", cmsg, msgsz);
+  putline(OK "maildir: %d message(s) %ld octet(s)", cmsg, (long int)msgsz);
 }
 
 static char *msgfn(int n) {
@@ -397,7 +397,8 @@
   int r;
   struct popdata d;
   const char *u = NULL;
-
+  const char **ptr_u = &u;
+  
   d.pass = pass;
   d.msg = NULL;
   convstruct.appdata_ptr = &d;
@@ -416,7 +417,7 @@
 	PAMOK(pam_set_item(pamh, PAM_RHOST, rhost)) &&
 	PAMOK(pam_authenticate(pamh, 0)) &&
 	PAMOK(pam_acct_mgmt(pamh, 0)) &&
-	PAMOK(pam_get_item(pamh, PAM_USER, (const void **)&u))) {
+	PAMOK(pam_get_item(pamh, PAM_USER, (const void **)ptr_u))) {
     pw = getpwnam(u && *u ? u : user); /* use username from pam if any */
     if (!maildir) /* try to get MAILDIR from PAM */
       maildir = pam_getenv(pamh, maildirenv);
@@ -450,22 +451,17 @@
   return NULL;
 
 #else /* !USE_PAM */
-
-  char *p;
-  if ((pw = getpwnam(user)) != NULL) {
-    p = pw->pw_passwd;
-    if (!p || !strcmp(p, "x")) {
-      struct spwd *sp = getspnam(user);
-      p = sp ? sp->sp_pwdp : NULL;
-      endspent();
-    }
-    if (p && strcmp(crypt(pass, p), p) == 0)
+    
+  pw = getpwnam(user);
+  endpwent();
+  if (pw != NULL)
+   {
+    if (pw->pw_passwd && strcmp(crypt(pass, pw->pw_passwd), pw->pw_passwd) == 0)
       return pw;
     syslog(LOG_INFO, "[%s] login incorrect for [%s]", rhost, user);
   }
   else
     syslog(LOG_INFO, "[%s] user unknown: [%s]", rhost, user);
-  sleep(3);
   putline(ERR "login incorrect");
   return NULL;
 
@@ -565,7 +561,7 @@
       *s = ':';
   }
   else
-    putmline("%s%d %ld", code, n+1, msgp[n]->size);
+    putmline("%s%d %ld", code, n+1, (long int)msgp[n]->size);
 }
 
 static void finalupdate() {
@@ -621,7 +617,7 @@
 
 static void finallog(const char *why) {
   syslog(LOG_INFO, "[%s][%s] %s (%d/%ld msgs/bytes left, %d/%ld deleted)",
-         rhost, user, why, cmsg, msgsz, o_nmsg - cmsg, o_msgsz - msgsz);
+         rhost, user, why, cmsg, (long int)msgsz, o_nmsg - cmsg, (long int)o_msgsz - (long int)msgsz);
 }
 
 static void die(const char *why) {
@@ -932,7 +928,7 @@
       else if (a)
 	extraarg(), --junk;
       else
-	putline(OK "%d %ld", cmsg, msgsz);
+	putline(OK "%d %ld", cmsg, (long int)msgsz);
     }
 
     else if (!strcmp(line, "top") || !strcmp(line, "retr")) {
