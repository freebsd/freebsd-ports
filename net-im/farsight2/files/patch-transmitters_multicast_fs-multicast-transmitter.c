--- transmitters/multicast/fs-multicast-transmitter.c.orig	2009-08-01 16:47:43.000000000 -0400
+++ transmitters/multicast/fs-multicast-transmitter.c	2009-08-01 16:48:29.000000000 -0400
@@ -53,6 +53,7 @@
 #else /*G_OS_WIN32*/
 # include <netdb.h>
 # include <sys/socket.h>
+# include <netinet/in.h>
 # include <netinet/ip.h>
 # include <arpa/inet.h>
 #endif /*G_OS_WIN32*/
