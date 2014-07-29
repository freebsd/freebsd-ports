--- Xvnc/programs/Xserver/hw/vnc/sockets.c      Tue Mar 19 18:59:22 2002
+++ Xvnc/programs/Xserver/hw/vnc/sockets.c      Fri Nov  1 18:03:02 2002
@@ -38,6 +38,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/socket.h>
