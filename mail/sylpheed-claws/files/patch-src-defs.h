--- ./src/defs.h.orig	Fri Nov 16 09:47:26 2001
+++ ./src/defs.h	Fri Dec 21 01:02:01 2001
@@ -65,8 +65,8 @@
 #define MARK_VERSION		2
 
 #define DEFAULT_SIGNATURE	".signature"
-#define DEFAULT_INC_PATH	"/usr/bin/mh/inc"
-#define DEFAULT_INC_PROGRAM	"inc"
+#define DEFAULT_INC_PATH	""
+#define DEFAULT_INC_PROGRAM	""
 /* #define DEFAULT_INC_PATH	"/usr/bin/imget" */
 /* #define DEFAULT_INC_PROGRAM	"imget" */
 #define DEFAULT_SENDMAIL_CMD	"/usr/sbin/sendmail -t"
@@ -74,7 +74,7 @@
 #ifdef _PATH_MAILDIR
 #  define DEFAULT_SPOOL_PATH	_PATH_MAILDIR
 #else
-#  define DEFAULT_SPOOL_PATH	"/var/spool/mail"
+#  define DEFAULT_SPOOL_PATH	"/var/mail"
 #endif
 
 #define BUFFSIZE			8192
