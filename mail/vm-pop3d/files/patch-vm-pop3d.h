--- vm-pop3d.h.orig	Fri Aug 24 19:28:57 2001
+++ vm-pop3d.h	Fri Aug 24 19:29:59 2001
@@ -63,7 +63,7 @@
 
 /* APOP password file, without .db or .passwd, which are added based on file
    type automatically */
-#define APOP_PASSFILE	"/etc/apop"
+#define APOP_PASSFILE	"%%PREFIX%%/etc/apop"
 
 /* Size of the MD5 digest for APOP */
 #define APOP_DIGEST	70
@@ -77,7 +77,7 @@
    The mailboxes for virtual domains do not have corresponding Unix
    accounts; they do not have unique UIDs; so they could be owned
    by one VIRTUAL_UID. */
-#define VIRTUAL_UID	8
+#define VIRTUAL_UID	65534
 
 /* VIRTUAL_MAILDIR is the path to the sub-directories containing
    the mailboxes for each virtual domain (or realm). It has a host,
@@ -92,7 +92,7 @@
    the sub-directories containing the password files for each virtual
    domain. By default, this is /etc/virtual.) */
 
-#define VIRTUAL_PASSWORDS_PATH  "/etc/virtual"
+#define VIRTUAL_PASSWORDS_PATH  "%%PREFIX%%/etc/virtual"
 
 /* VIRTUAL_PASSWORD_FNAME is the file name (or suffix) for the virtual
    domain's password file. (By default, this is "passwd". It could be set
