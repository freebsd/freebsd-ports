--- src/main.c.orig	2015-07-01 18:41:01 UTC
+++ src/main.c
@@ -131,8 +131,9 @@ int y;
 		perror("setsockopt(IP_PKTINFO) failed");
 #elif defined(IP_RECVDSTADDR) /* *BSD */
 	y = 1;
-	if (setsockopt(fd, IPPROTO_IP, IP_RECVDSTADDR,
-		       (const void *)&y, sizeof(y)) < 0)
+	if (family == AF_INET &&
+	    setsockopt(fd, IPPROTO_IP, IP_RECVDSTADDR,
+		(const void *)&y, sizeof(y)) < 0)
 		perror("setsockopt(IP_RECVDSTADDR) failed");
 #endif
 #if defined(IPV6_RECVPKTINFO)
