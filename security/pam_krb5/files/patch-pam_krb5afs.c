--- pam_krb5afs.c.orig	Mon Mar 10 15:37:00 2003
+++ pam_krb5afs.c	Wed Jan 21 15:19:16 2004
@@ -108,7 +108,6 @@
 #define MODULE_RET_NAME MODULE_NAME "_ret_stash"
 
 #define PAM_SM_AUTH
-#define PAM_SM_ACCT_MGMT
 #define PAM_SM_SESSION
 #define PAM_SM_PASSWORD
 
