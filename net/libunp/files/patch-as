--- lib/mcast_join.c-	Tue Feb  8 15:12:14 2000
+++ lib/mcast_join.c	Tue Feb  8 15:12:37 2000
@@ -56,7 +56,7 @@
 		else
 			mreq6.ipv6mr_interface = 0;
 
-		return(setsockopt(sockfd, IPPROTO_IPV6, IPV6_ADD_MEMBERSHIP,
+		return(setsockopt(sockfd, IPPROTO_IPV6, IPV6_JOIN_GROUP,
 						  &mreq6, sizeof(mreq6)));
 	}
 #endif
