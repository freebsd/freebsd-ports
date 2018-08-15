--- lib/eventlog/src/evtlog.h.orig	2018-04-25 04:54:49.000000000 -0700
+++ lib/eventlog/src/evtlog.h	2018-05-31 12:57:53.418401000 -0700
@@ -45,6 +45,8 @@
 #endif
 #include <stdarg.h>
 #include <arpa/inet.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 
 #include "evtmaps.h"
 
