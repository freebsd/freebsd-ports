--- ./bjoern/server.c.orig	2013-12-08 21:38:42.000000000 +0000
+++ ./bjoern/server.c	2014-08-23 14:45:32.000000000 +0000
@@ -1,6 +1,11 @@
 #ifdef WANT_SIGINT_HANDLING
 # include <sys/signal.h>
 #endif
+#if defined __FreeBSD__
+#include <netinet/in.h> /* struct sockaddr_in */
+#include <sys/types.h>
+#include <sys/socket.h>
+#endif
 #include <arpa/inet.h>
 #include <fcntl.h>
 #include <ev.h>
