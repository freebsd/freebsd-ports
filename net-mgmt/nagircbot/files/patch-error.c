--- error.c.orig	Sat Apr 28 14:08:54 2007
+++ error.c	Sat Apr 28 14:17:12 2007
@@ -5,6 +5,9 @@
 #include <sys/types.h>
 #include <signal.h>
 #include <syslog.h>
+#include <sys/param.h>
+#include <libutil.h>
+#include "anna.h"
 
 void error_exit(char *format, ...)
 {
@@ -17,6 +20,7 @@
 
 	fprintf(stderr, "%s: errno=%d (if applicable)\n", buffer, errno);
 	syslog(LOG_ERR, "'%s': %m", buffer);
+	pidfile_remove(pfh);
 
 	exit(EXIT_FAILURE);
 }
