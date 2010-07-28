--- ./src/plugins/lan/lan.c.orig	2009-02-25 15:38:53.000000000 -0500
+++ ./src/plugins/lan/lan.c	2010-07-23 14:46:07.000000000 -0400
@@ -36,6 +36,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/time.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <errno.h>
