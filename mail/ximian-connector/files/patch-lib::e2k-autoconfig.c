--- lib/e2k-autoconfig.c.orig	Tue May 11 11:09:03 2004
+++ lib/e2k-autoconfig.c	Tue Jun  1 20:47:50 2004
@@ -25,6 +25,10 @@
 
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <resolv.h>
 #include <arpa/nameser.h>
 
