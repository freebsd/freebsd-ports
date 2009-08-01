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
@@ -644,8 +645,10 @@ _bind_port (
     GST_WARNING ("could not set TOS: %s", g_strerror (errno));
 
   prio = 6;
+#ifdef SO_PRIORITY
   if (setsockopt (sock, SOL_SOCKET, SO_PRIORITY, &prio, sizeof (tos)) < 0)
     GST_WARNING ( "could not set socket priority: %s", g_strerror (errno));
+#endif
 
   address.sin_port = htons (port);
   retval = bind (sock, (struct sockaddr *) &address, sizeof (address));
