--- pop_pbs.c.orig	Mon Jul 16 11:38:00 2001
+++ pop_pbs.c	Mon Jul 16 11:41:40 2001
@@ -1,6 +1,7 @@
+#include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 
 char  addr_buf[256];
