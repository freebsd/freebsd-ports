--- xmit/nntpxmit.c.orig	Sat Dec  3 23:37:58 1994
+++ xmit/nntpxmit.c	Thu Nov  7 19:40:02 2002
@@ -64,8 +64,12 @@
 */
 
 #include "../conf.h"
+#ifdef BSD_44
+#define _ANSI_SOURCE
+#endif
 #include <stdio.h>
 #include <errno.h>
+#include <unistd.h>
 #include <ctype.h>
 #include <sys/types.h>
 #include <sys/time.h>
@@ -75,7 +79,9 @@
 #include <sys/times.h>
 extern	time_t	time();
 #endif
+#ifndef __FreeBSD__
 #include <sys/file.h>
+#endif
 #include <fcntl.h>
 #include <signal.h>
 #ifdef USG
@@ -445,7 +451,7 @@
 			/* Hmph. The file didn't exist. */
 			error = sendcmd(".");
 		} else {
-			error = !sendfile(fp);
+			error = !my_sendfile(fp);
 			/* Leave this open in case we need to requeue it. */
 		}
 		if (error) {
