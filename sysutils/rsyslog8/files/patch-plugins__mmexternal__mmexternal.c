--- plugins/mmexternal/mmexternal.c.orig	2014-11-25 15:45:35 UTC
+++ plugins/mmexternal/mmexternal.c
@@ -31,7 +31,7 @@
 #include <errno.h>
 #include <unistd.h>
 #include <fcntl.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <sys/uio.h>
 #include "conf.h"
 #include "syslogd-types.h"
