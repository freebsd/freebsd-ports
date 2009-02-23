--- src/idle-server-connection.c.orig	2009-02-23 01:02:04.000000000 -0500
+++ src/idle-server-connection.c	2009-02-23 01:05:04.000000000 -0500
@@ -28,9 +28,10 @@
 
 #include <arpa/inet.h>
 #include <fcntl.h>
-#include <netinet/tcp.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
+#include <netinet/tcp.h>
 #include <unistd.h>
 
 #define IDLE_DEBUG_FLAG IDLE_DEBUG_NETWORK
