--- lib/mcast_leave.c-	Tue Feb  8 15:10:50 2000
+++ lib/mcast_leave.c	Tue Feb  8 15:05:53 2000
@@ -23,7 +23,7 @@
 			   &((struct sockaddr_in6 *) sa)->sin6_addr,
 			   sizeof(struct in6_addr));
 		mreq6.ipv6mr_interface = 0;
-		return(setsockopt(sockfd, IPPROTO_IPV6, IPV6_DROP_MEMBERSHIP,
+		return(setsockopt(sockfd, IPPROTO_IPV6, IPV6_LEAVE_GROUP,
 						  &mreq6, sizeof(mreq6)));
 	}
 #endif
