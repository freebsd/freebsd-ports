--- src/defs.h.orig	Wed Aug 28 11:43:59 2002
+++ src/defs.h	Sun Sep  1 03:01:59 2002
@@ -70,8 +70,8 @@
 #define MARK_VERSION		2
 
 #define DEFAULT_SIGNATURE	".signature"
-#define DEFAULT_INC_PATH	"/usr/bin/mh/inc"
-#define DEFAULT_INC_PROGRAM	"inc"
+#define DEFAULT_INC_PATH	""
+#define DEFAULT_INC_PROGRAM	""
 /* #define DEFAULT_INC_PATH	"/usr/bin/imget" */
 /* #define DEFAULT_INC_PROGRAM	"imget" */
 #define DEFAULT_SENDMAIL_CMD	"/usr/sbin/sendmail -t"
@@ -79,7 +79,7 @@
 #ifdef _PATH_MAILDIR
 #  define DEFAULT_SPOOL_PATH	_PATH_MAILDIR
 #else
-#  define DEFAULT_SPOOL_PATH	"/var/spool/mail"
+#  define DEFAULT_SPOOL_PATH	"/var/mail"
 #endif
 
 #define BUFFSIZE			8192
