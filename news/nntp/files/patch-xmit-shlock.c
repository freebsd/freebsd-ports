--- xmit/shlock.c.orig	Tue Nov  1 06:54:32 1994
+++ xmit/shlock.c	Sun Jan  9 09:30:04 2000
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
+#ifdef BSD_44
+#define _ANSI_SOURCE
+#endif
+#include <stdio.h>
 
 #define	LOCK_SET	0
 #define	LOCK_FAIL	1
