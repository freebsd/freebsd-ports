--- src/pam_p11.c.orig	Sun Jun 11 21:16:46 2006
+++ src/pam_p11.c	Sun Jun 11 21:17:53 2006
@@ -39,7 +39,7 @@
 #define LOGNAME   "pam_p11"	/* name for log-file entries */
 
 #define RANDOM_SOURCE "/dev/urandom"
-#define RANDOM_SIZE 128
+#define RANDOM_SIZE 20
 #define MAX_SIGSIZE 256
 
 extern int match_user(X509 * x509, const char *login);
