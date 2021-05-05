--- src/socketworks.h.orig	2021-05-05 05:43:10 UTC
+++ src/socketworks.h
@@ -3,6 +3,7 @@
 #define MAX_SOCKS 300
 #include "utils.h"
 #include <netinet/in.h>
+#include <sys/socket.h>
 
 typedef int (*socket_action)(void *s);
 typedef int (*read_action)(int, void *, size_t, void *, int *);
