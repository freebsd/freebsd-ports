--- xmit/shlock.c.orig	Tue Nov  1 06:54:32 1994
+++ xmit/shlock.c	Tue Dec  3 05:04:26 2002
@@ -28,7 +28,6 @@
 ** Erik E. Fair <fair@apple.com>, November 12, 1989
 */
 
-#include <stdio.h>
 #include <sys/types.h>
 #include <fcntl.h>			/* Needed on hpux */
 #include <sys/file.h>
@@ -36,6 +35,10 @@
 #ifdef NNTPSRC
 #include "../conf.h"
 #endif
+#include <stdio.h>
+#ifdef __FreeBSD__
+#include <string.h>
+#endif
 
 #define	LOCK_SET	0
 #define	LOCK_FAIL	1
@@ -61,10 +64,12 @@
 
 #define	dprintf	if (Debug) printf
 
+#ifndef __FreeBSD__
 extern	int	errno;
 extern	char	*rindex();
 extern	char	*strcpy();
 extern	char	*strcat();
+#endif
 
 main(ac, av)
 int	ac;
@@ -118,8 +123,10 @@
 errmsg(n)
 register int	n;
 {
+#ifndef __FreeBSD__
 	extern	int	sys_nerr;
 	extern 	char	*sys_errlist[];
+#endif
 
 	return((n >= 0 && n < sys_nerr) ? sys_errlist[n] : "unknown error");
 }
