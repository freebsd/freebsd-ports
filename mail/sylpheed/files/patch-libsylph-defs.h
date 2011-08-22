--- libsylph/defs.h.orig	Tue Sep 13 16:55:49 2005
+++ libsylph/defs.h	Mon Sep 19 03:23:15 2005
@@ -81,8 +81,8 @@
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
@@ -91,7 +91,7 @@
 #ifdef _PATH_MAILDIR
 #  define DEFAULT_SPOOL_PATH	_PATH_MAILDIR
 #else
-#  define DEFAULT_SPOOL_PATH	"/var/spool/mail"
+#  define DEFAULT_SPOOL_PATH	"/var/mail"
 #endif
 
 #define BUFFSIZE			8192
