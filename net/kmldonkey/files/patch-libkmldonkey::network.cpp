--- libkmldonkey/network.cpp.orig	Sun May 11 14:26:34 2003
+++ libkmldonkey/network.cpp	Sun May 11 14:26:40 2003
@@ -28,6 +28,7 @@
  *
  */
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
