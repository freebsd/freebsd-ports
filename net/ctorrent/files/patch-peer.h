--- peer.h.orig	Fri Jan 16 00:30:15 2004
+++ peer.h	Sun Jan 18 02:44:04 2004
@@ -6,6 +6,7 @@
 #ifdef WINDOWS
 #include <Winsock2.h>
 #else
+#include <string.h>
 #include <unistd.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
