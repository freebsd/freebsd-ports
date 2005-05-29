--- src/app.c.orig	Tue May 24 20:19:17 2005
+++ src/app.c	Tue May 24 20:20:30 2005
@@ -60,6 +60,9 @@
 
 #ifdef HAVE_SECURITY_PAM_MISC_H
 #include <security/pam_misc.h>
+#else
+#include <security/openpam.h>
+#define misc_conv	openpam_ttyconv
 #endif
 
 #ifdef HAVE_PAM_PAM_MISC_H
