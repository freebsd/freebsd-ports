--- inc/address.hpp.orig	2011-09-10 17:59:50.000000000 +0300
+++ inc/address.hpp	2014-01-06 17:32:36.000000000 +0200
@@ -25,9 +25,10 @@
 #include <winsock2.h>
 #include <ws2tcpip.h>
 #else
+#include <sys/types.h>
 #include <sys/socket.h>
-#include <netinet/in_systm.h>
 #include <netinet/in.h>
+#include <netinet/in_systm.h>
 #include <netinet/ip.h>
 #endif
 
