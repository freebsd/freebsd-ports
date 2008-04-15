--- src/pam_fprint.c.orig	2008-04-12 18:33:50.000000000 +0200
+++ src/pam_fprint.c	2008-04-12 18:34:31.000000000 +0200
@@ -23,7 +23,7 @@
 #include <pwd.h>
 #include <string.h>
 
-#include <fprint.h>
+#include "libfprint/fprint.h"
 
 #define PAM_SM_AUTH
 #include <security/pam_modules.h>
