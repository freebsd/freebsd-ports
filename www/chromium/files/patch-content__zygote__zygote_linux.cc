--- content/zygote/zygote_linux.cc.orig	2012-07-26 22:17:55.696652102 +0300
+++ content/zygote/zygote_linux.cc	2012-07-26 22:19:42.568652054 +0300
@@ -9,6 +9,9 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
 
 #include "base/command_line.h"
 #include "ipc/ipc_switches.h"
