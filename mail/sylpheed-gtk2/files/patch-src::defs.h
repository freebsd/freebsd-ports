--- src/defs.h.orig	Sun Jun 13 23:42:41 2004
+++ src/defs.h	Wed Jun 16 02:57:31 2004
@@ -60,11 +60,11 @@
 #define CACHE_FILE		".sylpheed_cache"
 #define MARK_FILE		".sylpheed_mark"
 /*#warning FIXME_GTK2 */
-#define CACHE_VERSION		2018
+#define CACHE_VERSION		2019
 #define MARK_VERSION		2
 
 #define DEFAULT_SIGNATURE	".signature"
-#define DEFAULT_INC_PATH	"/usr/bin/mh/inc"
+#define DEFAULT_INC_PATH	""
 #define DEFAULT_INC_PROGRAM	"inc"
 /* #define DEFAULT_INC_PATH	"/usr/bin/imget" */
 /* #define DEFAULT_INC_PROGRAM	"imget" */
@@ -74,7 +74,7 @@
 #ifdef _PATH_MAILDIR
 #  define DEFAULT_SPOOL_PATH	_PATH_MAILDIR
 #else
-#  define DEFAULT_SPOOL_PATH	"/var/spool/mail"
+#  define DEFAULT_SPOOL_PATH	"/var/mail"
 #endif
 
 #define BUFFSIZE			8192
