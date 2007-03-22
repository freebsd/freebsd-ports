--- oRTP/src/stun_udp.c.orig	Fri Sep 22 16:19:58 2006
+++ oRTP/src/stun_udp.c	Sun Feb 25 03:36:37 2007
@@ -71,10 +71,10 @@
 #include <string.h>
 #include <stdio.h>
 #if !defined(WIN32) && !defined(_WIN32_WCE)
+#include <sys/types.h> 
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <sys/time.h>
-#include <sys/types.h> 
 #include <arpa/inet.h>
 #include <fcntl.h>
 #include <netdb.h>
