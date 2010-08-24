--- xvt/command.c.orig	2010-08-24 07:23:55.000000000 +0000
+++ xvt/command.c	2010-08-24 07:25:30.000000000 +0000
@@ -36,7 +36,12 @@
 #include <unistd.h>
 #include <signal.h>
 #include <fcntl.h>
-#include <utmp.h>
+#include <sys/param.h>
+#if __FreeBSD_version >= 900007
+#    include <utmpx.h>
+#else
+#    include <utmp.h>
+#endif
 #include <errno.h>
 #include <string.h>
 #include "xvt.h"
