--- smtptrapd.c.orig	2007-12-07 12:09:31.000000000 +0900
+++ smtptrapd.c	2008-02-01 00:11:37.000000000 +0900
@@ -27,9 +27,9 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <unistd.h>
-#include <arpa/inet.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <errno.h>
 #include <string.h>
 #include <sysexits.h>
@@ -544,7 +544,11 @@
 	/* background the process */
 	if (fork()) exit(0);
 	if (fork()) exit(0);
+#ifdef __FreeBSD__
+	setpgrp(0, 0);
+#else
 	setpgrp(); 
+#endif
 
 	openlog("smtptrapd", LOG_PID, LOG_MAIL);
 
