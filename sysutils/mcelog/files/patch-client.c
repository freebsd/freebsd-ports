--- client.c.orig	2016-02-10 18:38:43 UTC
+++ client.c
@@ -18,6 +18,7 @@
 #include <stdio.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#include <string.h>
 #include <unistd.h>
 #include "mcelog.h"
 #include "client.h"
@@ -48,6 +49,9 @@ void ask_server(char *command) 
 			sizeof(struct sockaddr_un)) < 0)
 		SYSERRprintf("client connect");
 	
+#ifdef __FreeBSD__
+	/* XXX: Need to use sendmsg() to send a SCM_CREDS control message. */
+#endif
 	n = strlen(command);
 	if (write(fd, command, n) != n)
 		SYSERRprintf("client command write");
