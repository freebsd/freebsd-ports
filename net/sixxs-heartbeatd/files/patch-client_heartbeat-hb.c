
$FreeBSD$

--- client/hb.c.orig	Tue Aug 10 08:10:03 2004
+++ client/hb.c	Tue Aug 10 08:09:11 2004
@@ -91,7 +91,7 @@
 	hints.ai_socktype = SOCK_DGRAM;
 
 	// Get the POP IPv4 into a sockaddr
-	if (getaddrinfo(sIPv4POP, PORT, &hints, &res) < 0)
+	if (getaddrinfo(sIPv4POP, PORT, &hints, &res) != 0)
 	{
 		hblog(LOG_ERR, "Couldn't resolve POP ip %s\n", sIPv4POP);
 		close(sockfd);
@@ -147,7 +147,7 @@
 		hints.ai_socktype = SOCK_DGRAM;
 		
 		// Get the POP IPv4 into a sockaddr
-		if (getaddrinfo(sIPv4LocalResolve, NULL, &hints, &res) < 0)
+		if (getaddrinfo(sIPv4LocalResolve, NULL, &hints, &res) != 0)
 		{
 			hblog(LOG_ERR, "Couldn't resolve POP ip %s\n", sIPv4POP);
 			// We return a -1, thus the app will keep beating
