--- lib/e2k-autoconfig.c.orig	Tue May 11 11:15:58 2004
+++ lib/e2k-autoconfig.c	Thu Jun 17 14:02:58 2004
@@ -31,6 +31,10 @@
 #include <sys/stat.h>
 #include <unistd.h>
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <netinet/in.h>
 #include <arpa/nameser.h>
 #include <resolv.h>
