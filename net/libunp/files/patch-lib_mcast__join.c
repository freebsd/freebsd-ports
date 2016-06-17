--- lib/mcast_join.c.orig	1997-06-19 03:15:06 UTC
+++ lib/mcast_join.c
@@ -56,7 +56,7 @@ doioctl:
 		else
 			mreq6.ipv6mr_interface = 0;
 
-		return(setsockopt(sockfd, IPPROTO_IPV6, IPV6_ADD_MEMBERSHIP,
+		return(setsockopt(sockfd, IPPROTO_IPV6, IPV6_JOIN_GROUP,
 						  &mreq6, sizeof(mreq6)));
 	}
 #endif
