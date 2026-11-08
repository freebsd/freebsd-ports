--- tac_plus.c.orig	2014-12-30 20:58:49.000000000 +0100
+++ tac_plus.c	2026-10-01 12:19:26.387755000 +0200
@@ -620,7 +620,7 @@
 	int pid;
 #endif
 	char host[NI_MAXHOST];
-	struct sockaddr_in from;
+	struct sockaddr_storage from;
 	socklen_t from_len;
 	int newsockfd = -1;
 	int flags, status;
@@ -671,8 +673,18 @@
 
 	if (session.peerip)
 	    free(session.peerip);
-	session.peerip = tac_strdup((char *)inet_ntop(from.sin_family,
-				    &from.sin_addr, host, NI_MAXHOST));
+	if (from.ss_family == AF_INET)
+	{
+	    struct sockaddr_in *sin = (struct sockaddr_in *) &from;
+	    session.peerip = tac_strdup((char *)inet_ntop(from.ss_family,
+				        &(sin->sin_addr), host, NI_MAXHOST));
+	}
+	else
+	{
+	    struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *) &from;
+	    session.peerip = tac_strdup((char *)inet_ntop(from.ss_family,
+				        &(sin6->sin6_addr), host, NI_MAXHOST));
+	}
 	if (debug & DEBUG_PACKET_FLAG)
 	    report(LOG_DEBUG, "session request from %s sock=%d",
 		   session.peer, newsockfd);
