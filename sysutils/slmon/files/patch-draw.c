--- draw.c.orig	Mon Jun 21 00:56:48 2004
+++ draw.c	Sun May 29 21:47:00 2005
@@ -27,7 +27,9 @@
 #include <glibtop/netload.h>
 
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 
 /*
  * Clear screen using color n. This should be used instead of SLsmg_cls() to
