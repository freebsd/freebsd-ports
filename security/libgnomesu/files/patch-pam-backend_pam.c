--- pam-backend/pam.c.orig	Thu Jan 13 23:43:53 2005
+++ pam-backend/pam.c	Thu Jan 13 23:43:59 2005
@@ -17,7 +17,7 @@
  */
 
 #include <security/pam_appl.h>
-#include <security/pam_misc.h>
+#include <security/pam_mod_misc.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
