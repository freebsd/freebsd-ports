--- src/udp-serv.c.orig	2011-05-27 13:22:44.000000000 +0400
+++ src/udp-serv.c	2011-05-27 13:22:54.000000000 +0400
@@ -1,6 +1,7 @@
 #include <stdio.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
