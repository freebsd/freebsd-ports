--- transmitters/rawudp/fs-rawudp-transmitter.h.orig	2009-02-27 23:30:18.000000000 -0500
+++ transmitters/rawudp/fs-rawudp-transmitter.h	2009-02-27 23:30:37.000000000 -0500
@@ -34,6 +34,9 @@
 #ifdef G_OS_WIN32
 # include <ws2tcpip.h>
 #else /*G_OS_WIN32*/
+# include <sys/types.h>
+# include <sys/socket.h>
+# include <netinet/in.h>
 # include <arpa/inet.h>
 #endif /*G_OS_WIN32*/
 
