--- xmit/nntpxmit.c.orig	Sat Dec  3 23:37:58 1994
+++ xmit/nntpxmit.c	Tue Dec  3 05:02:55 2002
@@ -66,6 +66,7 @@
 #include "../conf.h"
 #include <stdio.h>
 #include <errno.h>
+#include <unistd.h>
 #include <ctype.h>
 #include <sys/types.h>
 #include <sys/time.h>
@@ -75,7 +76,10 @@
 #include <sys/times.h>
 extern	time_t	time();
 #endif
+#ifndef __FreeBSD__
 #include <sys/file.h>
+#include <string.h>
+#endif
 #include <fcntl.h>
 #include <signal.h>
 #ifdef USG
@@ -148,6 +152,7 @@
 
 double Tbegin, Tend;		/* transfer timestamps */
 
+#ifndef __FreeBSD__
 extern	int	errno;
 extern 	int	strncmp();
 extern	char	*rindex();
@@ -155,6 +160,7 @@
 extern	char	*mktemp();
 extern	char	*strcpy();
 extern	char	*strcat();
+#endif
 
 main(ac, av)
 int	ac;
@@ -445,7 +451,7 @@
 			/* Hmph. The file didn't exist. */
 			error = sendcmd(".");
 		} else {
-			error = !sendfile(fp);
+			error = !my_sendfile(fp);
 			/* Leave this open in case we need to requeue it. */
 		}
 		if (error) {
@@ -515,8 +521,10 @@
 errmsg(code)
 int code;
 {
+#ifndef __FreeBSD__
 	extern int sys_nerr;
 	extern char *sys_errlist[];
+#endif
 	static char ebuf[6+5+1];
 
 	if (code > sys_nerr || code < 0) {
