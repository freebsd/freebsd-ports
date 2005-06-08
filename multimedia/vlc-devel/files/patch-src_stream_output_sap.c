--- src/stream_output/sap.c.orig	Wed Jun  8 00:17:59 2005
+++ src/stream_output/sap.c	Wed Jun  8 00:18:14 2005
@@ -41,6 +41,7 @@
 #   include <ws2tcpip.h>
 #else
 #   include <netdb.h>
+#   include <sys/socket.h>
 #endif
 #include "charset.h"
 
