--- transmitters/rawudp/fs-rawudp-transmitter.c.orig	2009-08-03 16:20:07.000000000 -0400
+++ transmitters/rawudp/fs-rawudp-transmitter.c	2009-08-09 19:19:33.000000000 -0400
@@ -53,6 +53,8 @@
 #else /*G_OS_WIN32*/
 # include <netdb.h>
 # include <sys/socket.h>
+# include <netinet/in.h>
+# include <netinet/in_systm.h>
 # include <netinet/ip.h>
 # include <arpa/inet.h>
 #endif /*G_OS_WIN32*/
