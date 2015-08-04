--- plugins/omprog/omprog.c.orig	2015-04-30 08:50:16 UTC
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
