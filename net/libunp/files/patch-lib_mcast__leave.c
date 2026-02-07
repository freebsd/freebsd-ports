--- lib/mcast_leave.c.orig	1997-06-18 19:50:58 UTC
+++ lib/mcast_leave.c
@@ -23,7 +23,7 @@ mcast_leave(int sockfd, const SA *sa, so
 			   &((struct sockaddr_in6 *) sa)->sin6_addr,
 			   sizeof(struct in6_addr));
 		mreq6.ipv6mr_interface = 0;
-		return(setsockopt(sockfd, IPPROTO_IPV6, IPV6_DROP_MEMBERSHIP,
+		return(setsockopt(sockfd, IPPROTO_IPV6, IPV6_LEAVE_GROUP,
 						  &mreq6, sizeof(mreq6)));
 	}
 #endif
