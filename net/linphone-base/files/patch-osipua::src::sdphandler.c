
$FreeBSD$

--- osipua/src/sdphandler.c	2003/06/13 13:02:40	1.1
+++ osipua/src/sdphandler.c	2003/06/13 13:02:48
@@ -26,6 +26,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 
 #ifdef HAVE_IFADDRS_H
 #include <ifaddrs.h>
