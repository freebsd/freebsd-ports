
$FreeBSD$

--- network.c.orig	Wed Apr 10 23:09:33 2002
+++ network.c	Wed Apr 16 16:07:19 2003
@@ -14,9 +14,6 @@
 #include <stdio.h>
 #include <errno.h>
 #include <string.h>
-#include <sys/socket.h>
-#include <netinet/in.h>
-#include <arpa/inet.h>
 #include <netdb.h>
 #include <fcntl.h>
 #include <unistd.h>
@@ -25,7 +22,6 @@
 #include "l2tp.h"
 
 char hostname[256];
-unsigned int listen_addy = INADDR_ANY;  /* Address to listen on */
 struct sockaddr_in server, from;        /* Server and transmitter structs */
 int server_socket;              /* Server socket */
 #ifdef USE_KERNEL
@@ -47,7 +43,7 @@
     int length = sizeof (server);
     gethostname (hostname, sizeof (hostname));
     server.sin_family = AF_INET;
-    server.sin_addr.s_addr = htonl (listen_addy);
+    server.sin_addr = gconfig.addr;
     server.sin_port = htons (gconfig.port);
     if ((server_socket = socket (PF_INET, SOCK_DGRAM, 0)) < 0)
     {
