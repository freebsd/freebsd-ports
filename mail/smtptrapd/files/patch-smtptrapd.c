--- smtptrapd.c.orig	Sun Mar 20 00:01:06 2005
+++ smtptrapd.c	Sun Mar 20 00:01:36 2005
@@ -27,9 +27,9 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/socket.h>
-#include <netinet/in.h>
 #include <errno.h>
 #include <string.h>
 #include <sysexits.h>
@@ -491,7 +491,11 @@
 	/* background the process */
 	if (fork()) exit(0);
 	if (fork()) exit(0);
+#ifdef __FreeBSD__
+	setpgrp(0, 0);
+#else
 	setpgrp(); 
+#endif
 
 	openlog("smtptrapd", LOG_PID, LOG_MAIL);
 
