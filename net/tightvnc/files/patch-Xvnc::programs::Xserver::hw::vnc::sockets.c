--- Xvnc/programs/Xserver/hw/vnc/sockets.c      Tue Mar 19 18:59:22 2002
+++ Xvnc/programs/Xserver/hw/vnc/sockets.c      Fri Nov  1 18:03:02 2002
@@ -38,6 +38,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/socket.h>
@@ -491,6 +492,7 @@
     int sock;
     int one = 1;
 
+    memset(&addr, 0, sizeof(addr));
     addr.sin_family = AF_INET;
     addr.sin_port = htons(port);
     addr.sin_addr.s_addr = interface.s_addr;
