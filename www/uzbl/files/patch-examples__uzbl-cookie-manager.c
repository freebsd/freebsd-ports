--- examples/uzbl-cookie-manager.c.orig	2010-11-25 05:56:44.000000000 +0100
+++ examples/uzbl-cookie-manager.c	2010-12-01 00:18:04.000000000 +0100
@@ -1,5 +1,3 @@
-#define _POSIX_SOURCE
-
 #include <stdio.h>
 #include <errno.h>
 #include <string.h>
@@ -10,7 +8,7 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <sys/select.h>
-#include <sys/unistd.h>
+#include <unistd.h>
 
 #include <sys/stat.h>
 #include <sys/file.h>
@@ -36,7 +34,7 @@
   /* delete the cookie socket if it was left behind on a previous run */
   unlink(cookied_socket_path);
 
-  int socket_fd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
+  int socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
 
   if(socket_fd < 0) {
     fprintf(stderr, "socket failed (%s)\n", strerror(errno));
