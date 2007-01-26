--- lib/tcpsocket.h.orig	Fri Jan 26 03:21:01 2007
+++ lib/tcpsocket.h	Fri Jan 26 03:21:48 2007
@@ -24,6 +24,7 @@
 #define TCPSOCKET_H
 
 #include <string>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #include "netsocket.h"
 
