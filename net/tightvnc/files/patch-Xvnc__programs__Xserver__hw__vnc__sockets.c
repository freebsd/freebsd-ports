--- Xvnc/programs/Xserver/hw/vnc/sockets.c.orig	2006-12-23 12:07:55 UTC
+++ Xvnc/programs/Xserver/hw/vnc/sockets.c
@@ -38,6 +38,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/socket.h>
