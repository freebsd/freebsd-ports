--- src/scrun/commands.c.orig	2023-11-21 22:33:29 UTC
+++ src/scrun/commands.c
@@ -39,6 +39,10 @@
 #include <signal.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <sys/signal.h>
+#endif
+
 #include "src/common/daemonize.h"
 #include "src/common/fd.h"
 #include "src/common/log.h"
