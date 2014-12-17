--- plugins/omprog/omprog.c.orig	2014-11-25 15:45:35 UTC
+++ plugins/omprog/omprog.c
@@ -36,7 +36,7 @@
 #include <errno.h>
 #include <unistd.h>
 #include <fcntl.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <pthread.h>
 #include "conf.h"
 #include "syslogd-types.h"
