--- params.h.orig	Mon Feb 23 17:07:38 2004
+++ params.h	Sun Apr 18 19:16:14 2004
@@ -22,12 +22,12 @@
  * will probably want to set this to 1 for their builds of John.
  */
 #ifndef JOHN_SYSTEMWIDE
-#define JOHN_SYSTEMWIDE			0
+#define JOHN_SYSTEMWIDE			1
 #endif
 
 #if JOHN_SYSTEMWIDE
-#define JOHN_SYSTEMWIDE_EXEC		"/usr/libexec/john"
-#define JOHN_SYSTEMWIDE_HOME		"/usr/share/john"
+#define JOHN_SYSTEMWIDE_EXEC		"%%PREFIX%%/bin/john"
+#define JOHN_SYSTEMWIDE_HOME		"%%PREFIX%%/share/john"
 #define JOHN_PRIVATE_HOME		"~/.john"
 #endif
 
@@ -67,8 +67,8 @@
 /*
  * File names.
  */
-#define CFG_FULL_NAME			"$JOHN/john.conf"
-#define CFG_ALT_NAME			"$JOHN/john.ini"
+#define CFG_FULL_NAME		"%%PREFIX%%/share/john/john.conf"
+#define CFG_ALT_NAME		"%%PREFIX%%/share/john/john.ini"
 #if JOHN_SYSTEMWIDE
 #define CFG_PRIVATE_FULL_NAME		JOHN_PRIVATE_HOME "/john.conf"
 #define CFG_PRIVATE_ALT_NAME		JOHN_PRIVATE_HOME "/john.ini"
@@ -82,7 +82,7 @@
 #endif
 #define LOG_SUFFIX			".log"
 #define RECOVERY_SUFFIX			".rec"
-#define WORDLIST_NAME			"$JOHN/password.lst"
+#define WORDLIST_NAME		"%%PREFIX%%/share/john/password.lst"
 
 /*
  * Configuration file section names.
