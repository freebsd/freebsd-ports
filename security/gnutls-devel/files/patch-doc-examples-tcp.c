--- doc/examples/tcp.c.orig	Sat Aug 26 20:46:20 2006
+++ doc/examples/tcp.c	Sat Aug 26 20:47:53 2006
@@ -9,6 +9,7 @@
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #include <unistd.h>
+#include <netinet/in.h>
 
 #define SA struct sockaddr
 
