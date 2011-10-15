--- ./client.c.orig	2009-12-15 07:18:40.000000000 -0500
+++ ./client.c	2011-10-14 22:36:47.000000000 -0400
@@ -18,6 +18,7 @@
 #include <stdio.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#include <string.h>
 #include <unistd.h>
 #include "mcelog.h"
 #include "client.h"
@@ -48,6 +49,9 @@
 			sizeof(struct sockaddr_un)) < 0)
 		SYSERRprintf("client connect");
 	
+#ifdef __FreeBSD__
+	/* XXX: Need to use sendmsg() to send a SCM_CREDS control message. */
+#endif
 	n = strlen(command);
 	if (write(fd, command, n) != n)
 		SYSERRprintf("client command write");
