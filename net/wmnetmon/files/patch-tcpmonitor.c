--- tcpmonitor.c.orig	1999-07-23 13:58:24 UTC
+++ tcpmonitor.c
@@ -12,7 +12,9 @@
 #include <sys/time.h>
 #include <arpa/inet.h>
 #include <stdlib.h>
+#if ! (defined __FreeBSD__ || defined __DragonFly__)
 #include <malloc.h>
+#endif
 #include <fcntl.h>
 #include <errno.h>
 #include "config.h"
@@ -51,7 +53,7 @@ int tcp_isalive(pinger_host *h)
 	if (debug)
 	fprintf(stderr,"trying to connect (tcp) to port %d at %s...\n", h->tcpport,
 	    inet_ntoa(h->tcpsock->sin_addr));
-	if (connect(h->tcp_socket, (struct sockaddr_in*)h->tcpsock, 
+	if (connect(h->tcp_socket, (struct sockaddr*)h->tcpsock, 
 	        sizeof(struct sockaddr_in))<0) 
 	   switch(errno) {
 		case EISCONN: /* Common.. reported by lots of users 
