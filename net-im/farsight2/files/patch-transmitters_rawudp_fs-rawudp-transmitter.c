--- transmitters/rawudp/fs-rawudp-transmitter.c.orig	2009-08-03 16:20:07.000000000 -0400
+++ transmitters/rawudp/fs-rawudp-transmitter.c	2009-08-08 14:47:44.000000000 -0400
@@ -53,6 +53,7 @@
 #else /*G_OS_WIN32*/
 # include <netdb.h>
 # include <sys/socket.h>
+# include <netinet/in.h>
 # include <netinet/ip.h>
 # include <arpa/inet.h>
 #endif /*G_OS_WIN32*/
