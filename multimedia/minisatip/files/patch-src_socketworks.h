--- src/socketworks.h.orig	2020-08-16 05:56:14 UTC
+++ src/socketworks.h
@@ -2,6 +2,7 @@
 #define SOCKETWORKS_H
 #define MAX_SOCKS 300
 #include <netinet/in.h>
+#include <sys/socket.h>
 #include "utils.h"
 
 typedef int (*socket_action)(void *s);
