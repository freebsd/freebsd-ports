--- pty.c.orig	Sun May 11 14:28:53 2003
+++ pty.c	Fri Feb 13 15:06:26 2004
@@ -14,7 +14,9 @@
 #define _XOPEN_SOURCE
 #define _XOPEN_SOURCE_EXTENDED
 #define _GNU_SOURCE
+#ifndef __FreeBSD__
 #include <features.h>
+#endif
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -32,6 +34,10 @@
 #include <sys/ioctl.h>
 #include <errno.h>
 
+#ifdef __FreeBSD__
+#include <sys/stat.h>
+#endif
+
 #include "putty.h"
 
 #ifndef FALSE
@@ -567,9 +573,9 @@
 	ioctl(slavefd, TIOCSCTTY, 1);
 	pgrp = getpid();
 	tcsetpgrp(slavefd, pgrp);
-	setpgrp();
+	setpgrp( pgrp, -1 );
 	close(open(pty_name, O_WRONLY, 0));
-	setpgrp();
+	setpgrp( pgrp, -1 );
 	/* Close everything _else_, for tidiness. */
 	for (i = 3; i < 1024; i++)
 	    close(i);
