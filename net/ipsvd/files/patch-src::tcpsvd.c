--- src/tcpsvd.c.orig	Tue May  6 00:58:40 2003
+++ src/tcpsvd.c	Tue May  6 00:58:59 2003
@@ -1,3 +1,4 @@
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <unistd.h>
