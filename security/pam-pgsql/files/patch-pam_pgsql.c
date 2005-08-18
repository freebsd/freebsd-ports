--- pam_pgsql.c.orig	Wed Aug 17 00:05:28 2005
+++ pam_pgsql.c	Wed Aug 17 00:06:51 2005
@@ -17,10 +17,10 @@
 #include <time.h>
 #include <sys/time.h>
 #include <libpq-fe.h>
-#include <crypt.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <netdb.h>
+#include <security/pam_appl.h>
 
 #define PAM_SM_AUTH
 #define PAM_SM_ACCOUNT
