--- librabbitmq/amqp_tcp_socket.c.orig	2015-06-17 07:41:33 UTC
+++ librabbitmq/amqp_tcp_socket.c
@@ -32,6 +32,9 @@
 #ifndef _WIN32
 # include <netinet/tcp.h>
 #endif
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <stdio.h>
 #include <stdlib.h>
 
