--- libsylph/defs.h.orig	2012-03-26 07:27:43 UTC
+++ libsylph/defs.h
@@ -89,8 +89,8 @@
 #else
 #  define DEFAULT_SIGNATURE	".signature"
 #endif
-#define DEFAULT_INC_PATH	"/usr/bin/mh/inc"
-#define DEFAULT_INC_PROGRAM	"inc"
+#define DEFAULT_INC_PATH	""
+#define DEFAULT_INC_PROGRAM	""
 /* #define DEFAULT_INC_PATH	"/usr/bin/imget" */
 /* #define DEFAULT_INC_PROGRAM	"imget" */
 #define DEFAULT_SENDMAIL_CMD	"/usr/sbin/sendmail -t -i"
@@ -103,7 +103,7 @@
 #ifdef _PATH_MAILDIR
 #  define DEFAULT_SPOOL_PATH	_PATH_MAILDIR
 #else
-#  define DEFAULT_SPOOL_PATH	"/var/spool/mail"
+#  define DEFAULT_SPOOL_PATH	"/var/spool"
 #endif
 
 #define BUFFSIZE			8192
