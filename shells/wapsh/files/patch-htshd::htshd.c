--- htshd/htshd.c.orig	Sat Jan 13 17:35:54 2001
+++ htshd/htshd.c	Sat Jan 13 17:36:18 2001
@@ -97,10 +97,10 @@
 #define SERVICE_NAME "htsh"	/* Should be in /etc/services
                                    on login and http server hosts */
 
-#define CONFIG_FILE "/etc/htshd.conf"
+#define CONFIG_FILE "%%PREFIX%%/etc/wapsh/htshd.conf"
 				/* Default name of startup config file */
 
-#define GLOBAL_RC_FILE "/etc/htsh_profile"
+#define GLOBAL_RC_FILE "%%PREFIX%%/etc/wapsh/htsh_profile"
 				/* Default name of global user 
 				   initialisation file */
 #define RCFILE ".htshrc"	/* Name of user-specific initialisation file
