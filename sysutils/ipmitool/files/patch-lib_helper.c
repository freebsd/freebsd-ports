--- lib/helper.c.orig	Wed May 18 03:58:05 2005
+++ lib/helper.c	Tue May 31 22:01:31 2005
@@ -34,17 +34,20 @@
  * facility.
  */
 
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <sys/ioctl.h>	/* For TIOCNOTTY */
+
 #include <stdlib.h>
 #include <stdio.h>
 #include <inttypes.h>
 #include <signal.h>
 #include <string.h>
 #include <strings.h>
-#include <sys/types.h>
-#include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <paths.h>		/* For _PATH_TTY */
 
 #include <ipmitool/helper.h>
 #include <ipmitool/log.h>
