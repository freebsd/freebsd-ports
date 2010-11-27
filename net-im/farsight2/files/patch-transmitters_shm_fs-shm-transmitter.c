--- transmitters/shm/fs-shm-transmitter.c.orig	2010-11-26 23:51:31.000000000 -0500
+++ transmitters/shm/fs-shm-transmitter.c	2010-11-26 23:50:40.000000000 -0500
@@ -52,7 +52,9 @@
 # define close closesocket
 #else /*G_OS_WIN32*/
 # include <netdb.h>
+# include <sys/types.h>
 # include <sys/socket.h>
+# include <netinet/in.h>
 # include <netinet/ip.h>
 # include <arpa/inet.h>
 #endif /*G_OS_WIN32*/
