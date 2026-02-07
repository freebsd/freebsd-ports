--- runtime/netns_socket.c.orig	2025-10-15 19:14:52 UTC
+++ runtime/netns_socket.c
@@ -24,6 +24,7 @@
 #include <string.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#include <unistd.h>
 
 #include "rsyslog.h"
 #include "debug.h"
