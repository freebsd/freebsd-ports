--- params.h	Sun Sep 15 20:19:20 2002
+++ params.h	Wed Jan 15 23:50:29 2003
@@ -26,8 +26,8 @@
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
@@ -78,7 +78,7 @@
 #define LOG_NAME			"$JOHN/john.pot"
 #define RECOVERY_NAME			"$JOHN/restore"
 #endif
-#define WORDLIST_NAME			"$JOHN/password.lst"
+#define WORDLIST_NAME		"%%PREFIX%%/share/john/password.lst"
 
 /*
  * Configuration file section names.
