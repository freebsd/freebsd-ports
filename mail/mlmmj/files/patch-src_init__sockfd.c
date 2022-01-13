--- src/init_sockfd.c.orig	2012-03-13 12:16:36 UTC
+++ src/init_sockfd.c
@@ -22,6 +22,7 @@
  */
 
 #include <stdlib.h>
+#include <stdio.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <unistd.h>
@@ -29,35 +30,53 @@
 #include <arpa/inet.h>
 #include <string.h>
 #include <inttypes.h>
+#include <netdb.h>
 
 #include "init_sockfd.h"
 #include "log_error.h"
 
 void init_sockfd(int *sockfd, const char *relayhost, unsigned short port)
 {
-	int len, on;
-	struct sockaddr_in addr;
+	int on, sd;
+	struct addrinfo *ai = NULL, *curai, hints;
+	char srv[NI_MAXSERV];
+	*sockfd = -1;
 
 	if (getenv("MLMMJ_TESTING")) {
 		relayhost = "127.0.0.1";
 		port = 10025;
 	}
 
-	*sockfd = socket(PF_INET, SOCK_STREAM, 0);
+	memset(&hints, 0, sizeof(hints));
+	hints.ai_socktype = SOCK_STREAM;
+	hints.ai_family = PF_UNSPEC;
+	snprintf(srv, sizeof(srv), "%d", port);
+	if (getaddrinfo(relayhost, srv, &hints, &ai) != 0) {
+		log_error(LOG_ARGS, "Unable to lookup for relayhost %s:%s",
+		    relayhost, srv);
+		return;
+	}
 	if(*sockfd == -1) {
 		log_error(LOG_ARGS, "Could not get socket");
 		return;
 	}
-	addr.sin_family = PF_INET;
-	addr.sin_addr.s_addr = inet_addr(relayhost);
-	addr.sin_port = htons(port);
-	len = sizeof(addr);
-	if(connect(*sockfd, (struct sockaddr *)&addr, len) == -1) {
+	for (curai = ai; curai != NULL; curai = curai->ai_next) {
+		if ((sd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol)) < 0) {
+			continue;
+		}
+		if (connect(sd, ai->ai_addr, ai->ai_addrlen) == 0) {
+			close(sd);
+			sd = -1;
+			continue;
+		}
+		break;
+	}
+	freeaddrinfo(ai);
+	if (sd == -1) {
 		log_error(LOG_ARGS, "Could not connect to %s", relayhost);
-		close(*sockfd);
-		*sockfd = -1;
 		return;
 	}
+	*sockfd = sd;
 
 	on = 1;
 	if(setsockopt(*sockfd, SOL_SOCKET, SO_KEEPALIVE, (void *)&on,
