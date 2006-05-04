--- params.h.orig	Sun Mar 19 20:34:15 2006
+++ params.h	Wed May  3 14:45:51 2006
@@ -49,15 +49,15 @@
  * notes above.
  */
 #ifndef JOHN_SYSTEMWIDE
-#define JOHN_SYSTEMWIDE			0
+#define JOHN_SYSTEMWIDE			1
 #endif
 
 #if JOHN_SYSTEMWIDE
 #ifndef JOHN_SYSTEMWIDE_EXEC /* please refer to the notes above */
-#define JOHN_SYSTEMWIDE_EXEC		"/usr/libexec/john"
+#define JOHN_SYSTEMWIDE_EXEC		"%%PREFIX%%/bin/john"
 #endif
 #ifndef JOHN_SYSTEMWIDE_HOME
-#define JOHN_SYSTEMWIDE_HOME		"/usr/share/john"
+#define JOHN_SYSTEMWIDE_HOME		"%%DATADIR%%"
 #endif
 #define JOHN_PRIVATE_HOME		"~/.john"
 #endif
@@ -101,8 +101,8 @@
 /*
  * File names.
  */
-#define CFG_FULL_NAME			"$JOHN/john.conf"
-#define CFG_ALT_NAME			"$JOHN/john.ini"
+#define CFG_FULL_NAME			"%%PREFIX%%/etc/john.conf"
+#define CFG_ALT_NAME			"%%PREFIX%%/etc/john.ini"
 #if JOHN_SYSTEMWIDE
 #define CFG_PRIVATE_FULL_NAME		JOHN_PRIVATE_HOME "/john.conf"
 #define CFG_PRIVATE_ALT_NAME		JOHN_PRIVATE_HOME "/john.ini"
@@ -116,7 +116,7 @@
 #endif
 #define LOG_SUFFIX			".log"
 #define RECOVERY_SUFFIX			".rec"
-#define WORDLIST_NAME			"$JOHN/password.lst"
+#define WORDLIST_NAME			"%%DATADIR%%/password.lst"
 
 /*
  * Configuration file section names.
