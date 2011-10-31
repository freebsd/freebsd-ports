--- ./src/acct.c.orig	2011-07-29 15:31:01.000000000 -0400
+++ ./src/acct.c	2011-10-18 11:49:37.000000000 -0400
@@ -38,7 +38,6 @@
 
 #ifdef HAVE_SECURITY_PAM_MODULES_H
 #define PAM_SM_ACCT_MGMT
-#include <security/pam_modules.h>
 #endif
 
 #include <errno.h>
