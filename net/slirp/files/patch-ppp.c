--- ppp.c.orig	Sun Nov 24 03:26:40 2002
+++ ppp.c	Sun Nov 24 03:26:54 2002
@@ -38,7 +38,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <syslog.h>
-#include <utmp.h>
+/* #include <utmp.h> */
 #include <pwd.h>
 
 #include <sys/param.h>
