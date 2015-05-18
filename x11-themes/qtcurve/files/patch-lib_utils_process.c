--- lib/utils/process.c.orig	2014-01-25 20:13:54 UTC
+++ lib/utils/process.c
@@ -23,7 +23,8 @@
 #include "fd_utils.h"
 #include "timer.h"
 #include <unistd.h>
-#include <wait.h>
+#include <signal.h>
+#include <sys/wait.h>
 #include <sys/stat.h>
 #include <sys/socket.h>
 #include <fcntl.h>
