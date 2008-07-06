--- loudmouth/lm-sock.c.orig	2008-07-06 15:41:02.000000000 -0400
+++ loudmouth/lm-sock.c	2008-07-06 15:43:01.000000000 -0400
@@ -27,8 +27,10 @@
 #include <errno.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <fcntl.h>
+#include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
