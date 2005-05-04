--- M4Systems/Tools/linux/os_net.c.orig	Tue Feb  1 13:50:56 2005
+++ M4Systems/Tools/linux/os_net.c	Wed May  4 13:09:09 2005
@@ -41,6 +41,9 @@
 #include <netinet/tcp.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
+#if __FreeBSD_osversion < 500000
+#include <sys/time.h>
+#endif
 
 
 #define INVALID_SOCKET -1
