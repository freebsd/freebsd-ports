--- src/lib-master/test-event-stats.c.orig	2018-11-23 14:47:35 UTC
+++ src/lib-master/test-event-stats.c
@@ -12,6 +12,7 @@
 #include "stats-client.h"
 #include "test-common.h"
 #include <fcntl.h>
+#include <signal.h>
 #include <unistd.h>
 #include <sys/socket.h>
 #include <sys/un.h>
