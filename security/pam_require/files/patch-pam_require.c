diff -rub pam_require.c pam_require.c
--- pam_require.c	Wed Sep 22 23:32:27 2004
+++ pam_require.c	Thu Mar 30 21:08:43 2006
@@ -49,7 +49,7 @@
 #include <grp.h>
 #include <pwd.h>
 #include <unistd.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <stdarg.h>
 
 /* taken from pam_ldap */
