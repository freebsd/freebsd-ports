--- Xvnc/programs/Xserver/hw/vnc/sockets.c.orig	Fri Nov 10 21:41:53 2000
+++ Xvnc/programs/Xserver/hw/vnc/sockets.c	Wed Nov 20 22:08:01 2002
@@ -38,6 +38,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/socket.h>
@@ -541,6 +542,7 @@
     int sock;
     int one = 1;
 
+    memset(&addr, 0, sizeof(addr));
     addr.sin_family = AF_INET;
     addr.sin_port = htons(port);
     addr.sin_addr.s_addr = interface.s_addr;
