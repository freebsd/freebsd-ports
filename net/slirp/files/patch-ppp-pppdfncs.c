--- ppp/pppdfncs.c.orig	Sun Nov 24 03:27:57 2002
+++ ppp/pppdfncs.c	Sun Nov 24 03:27:30 2002
@@ -28,7 +28,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <syslog.h>
-#include <utmp.h>
+/* #include <utmp.h> */
 #include <pwd.h>
 #include <sys/param.h>
 #include <sys/types.h>
