--- src/authinfo_pam.c.orig	Sun Jun 11 14:32:55 2000
+++ src/authinfo_pam.c	Wed Sep 26 11:27:09 2001
@@ -15,7 +15,9 @@
 #include "authinfo_pam.h"
 
 #include <security/pam_appl.h>
+#ifndef __FreeBSD__
 #include <security/pam_misc.h>
+#endif
 
 /*
  * pam authenticator.
