--- pam_oath/pam_oath.c.orig	2021-05-01 17:10:32 UTC
+++ pam_oath/pam_oath.c
@@ -21,6 +21,7 @@
 #include <config.h>
 
 #include "oath.h"
+#include "pam_modutil.h"
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -42,9 +43,6 @@
 
 #ifdef HAVE_SECURITY_PAM_APPL_H
 #include <security/pam_appl.h>
-#endif
-#ifdef HAVE_SECURITY_PAM_MODUTIL_H
-#include <security/pam_modutil.h>
 #endif
 #ifdef HAVE_SECURITY_PAM_MODULES_H
 #include <security/pam_modules.h>
