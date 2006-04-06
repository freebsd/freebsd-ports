--- htshd/htshd.c.orig	Fri Nov 24 15:46:01 2000
+++ htshd/htshd.c	Tue Nov 18 18:03:33 2003
@@ -97,10 +97,10 @@
 #define SERVICE_NAME "htsh"	/* Should be in /etc/services
                                    on login and http server hosts */
 
-#define CONFIG_FILE "/etc/htshd.conf"
+#define CONFIG_FILE "/usr/local/etc/wapsh/htshd.conf"
 				/* Default name of startup config file */
 
-#define GLOBAL_RC_FILE "/etc/htsh_profile"
+#define GLOBAL_RC_FILE "/usr/local/etc/wapsh/htsh_profile"
 				/* Default name of global user 
 				   initialisation file */
 #define RCFILE ".htshrc"	/* Name of user-specific initialisation file
