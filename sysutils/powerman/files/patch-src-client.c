$FreeBSD$

--- src/client.c.orig	Mon Mar 29 14:25:54 2004
+++ src/client.c	Mon Mar 29 14:27:27 2004
@@ -31,10 +31,14 @@
 #include <syslog.h>
 #include <stdarg.h>
 
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <tcpd.h>
 #include <stdio.h>
 #include <fcntl.h>
+#include <sys/socket.h>
+#include <limits.h>
 
 #include "powerman.h"
 #include "wrappers.h"
