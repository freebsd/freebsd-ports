--- extensions/dashboard/dashboard-frontend-xmlwriter.c.orig	Mon Feb  2 01:48:57 2004
+++ extensions/dashboard/dashboard-frontend-xmlwriter.c	Mon Feb  2 01:49:39 2004
@@ -32,6 +32,7 @@
 #include <unistd.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/time.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <fcntl.h>
