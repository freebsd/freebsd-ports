--- xmit/nntpxmit.c.orig	Sat Dec  3 23:37:58 1994
+++ xmit/nntpxmit.c	Mon Nov  4 05:55:31 2002
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
@@ -445,7 +449,7 @@
 			/* Hmph. The file didn't exist. */
 			error = sendcmd(".");
 		} else {
-			error = !sendfile(fp);
+			error = !my_sendfile(fp);
 			/* Leave this open in case we need to requeue it. */
 		}
 		if (error) {
