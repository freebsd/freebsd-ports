--- ./plugins/mmexternal/mmexternal.c.orig	2014-05-15 11:34:32.462046745 -0600
+++ ./plugins/mmexternal/mmexternal.c	2014-05-15 11:34:44.101043805 -0600
@@ -31,7 +31,7 @@
 #include <errno.h>
 #include <unistd.h>
 #include <fcntl.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <sys/uio.h>
 #include "conf.h"
 #include "syslogd-types.h"
