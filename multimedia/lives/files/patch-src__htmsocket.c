--- src/htmsocket.c.orig	2008-07-11 15:02:34.000000000 +0900
+++ src/htmsocket.c	2009-06-03 00:58:22.000000000 +0900
@@ -9,7 +9,10 @@
 #include <unistd.h>
 #include <netdb.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <sys/ioctl.h>
 
 #include "main.h"
