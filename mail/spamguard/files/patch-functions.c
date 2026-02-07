--- functions.c.orig	2008-01-21 15:41:05 UTC
+++ functions.c
@@ -10,16 +10,9 @@
 #include "wildmat.h"
 #include "hash.h"
 
-extern char mail_command[VALSIZE];
-extern char makemap_command[VALSIZE];
-extern char sysadmin[VALSIZE];
-extern char statfile[VALSIZE];
-extern char badmailfile[VALSIZE];
+maddr *spammer_hash[MAXADDR];
+iaddr *iaddrlist;
 
-extern int wcnt;
-extern int bcnt;
-extern int pcnt;
-
 extern int w;
 extern int b;
 extern int p;
@@ -107,7 +100,8 @@ send_notify_mail(char *n, char *sender, char *spam_typ
          	return errno;
         }
 
-        if ((bytes = write(fd, n, strlen(n))) < bytes) {
+	bytes = strlen(n);
+        if (write(fd, n, bytes) < bytes) {
                 fprintf(stderr, "Couldn't write to temporary file");
                 return errno;
         }
