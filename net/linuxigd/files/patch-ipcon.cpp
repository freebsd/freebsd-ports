--- ipcon.cpp.orig	Wed May 15 23:48:24 2002
+++ ipcon.cpp	Sat Aug  3 22:10:54 2002
@@ -25,7 +25,8 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <arpa/inet.h>
-#include <linux/sockios.h>
+#include <sys/sockio.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <netinet/in.h>
 #include <sys/ioctl.h>
