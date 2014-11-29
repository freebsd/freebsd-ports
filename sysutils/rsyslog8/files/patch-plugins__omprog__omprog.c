--- plugins/omprog/omprog.c.orig	2014-11-15 15:26:55.633028880 -0600
+++ plugins/omprog/omprog.c	2014-11-15 15:27:01.695054590 -0600
@@ -36,7 +36,7 @@
 #include <errno.h>
 #include <unistd.h>
 #include <fcntl.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <pthread.h>
 #include "conf.h"
 #include "syslogd-types.h"
