--- base/pam_eps/pam_eps_passwd.c.orig	Tue Jan 22 16:26:28 2002
+++ base/pam_eps/pam_eps_passwd.c	Tue Jan 22 16:26:42 2002
@@ -75,7 +75,6 @@
 #include <syslog.h>
 #include <string.h>
 #include <stdarg.h>
-#include <malloc.h>
 #include <t_pwd.h>
 
 #ifndef LINUX    /* AGM added this as of 0.2 */
