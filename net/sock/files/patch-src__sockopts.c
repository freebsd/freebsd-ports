--- src/sockopts.c.orig	2010-05-28 00:03:25 UTC
+++ src/sockopts.c
@@ -30,6 +30,13 @@ sockopts(int sockfd, int doall)
 	unsigned	optlen;
 	struct linger	ling;
 	struct timeval	timer;
+	int 		level;
+
+	if (AF_INET == af_46) {
+		level = IPPROTO_IP;
+	} else {
+		level = IPPROTO_IPV6;
+	}
 	
 	/* "doall" is 0 for a server's listening socket (i.e., before
 	   accept() has returned.)  Some socket options such as SO_KEEPALIVE
@@ -73,13 +80,13 @@ sockopts(int sockfd, int doall)
 	
 #ifdef	IP_TOS
 	if (iptos != -1 && doall == 0) {
-		if (setsockopt(sockfd, IPPROTO_IP, IP_TOS,
+		if (setsockopt(sockfd, level, IP_TOS,
 			       &iptos, sizeof(iptos)) < 0)
 			err_sys("IP_TOS setsockopt error");
 		
 		option = 0;
 		optlen = sizeof(option);
-		if (getsockopt(sockfd, IPPROTO_IP, IP_TOS,
+		if (getsockopt(sockfd, level, IP_TOS,
 			       &option, &optlen) < 0)
 			err_sys("IP_TOS getsockopt error");
 		if (option != iptos)
@@ -92,13 +99,13 @@ sockopts(int sockfd, int doall)
 	
 #ifdef	IP_TTL
 	if (ipttl != -1 && doall == 0) {
-		if (setsockopt(sockfd, IPPROTO_IP, IP_TTL,
+		if (setsockopt(sockfd, level, IP_TTL,
 			       &ipttl, sizeof(ipttl)) < 0)
 			err_sys("IP_TTL setsockopt error");
 		
 		option = 0;
 		optlen = sizeof(option);
-		if (getsockopt(sockfd, IPPROTO_IP, IP_TTL,
+		if (getsockopt(sockfd, level, IP_TTL,
 			       &option, &optlen) < 0)
 			err_sys("IP_TTL getsockopt error");
 		if (option != ipttl)
@@ -150,13 +157,13 @@ sockopts(int sockfd, int doall)
 #ifdef	IP_ONESBCAST
 		if (onesbcast) {
 			option = 1;
-			if (setsockopt(sockfd, IPPROTO_IP, IP_ONESBCAST,
+			if (setsockopt(sockfd, level, IP_ONESBCAST,
 				       &option, sizeof(option)) < 0)
 				err_sys("IP_ONESBCAST setsockopt error");
 			
 			option = 0;
 			optlen = sizeof(option);
-			if (getsockopt(sockfd, IPPROTO_IP, IP_ONESBCAST,
+			if (getsockopt(sockfd, level, IP_ONESBCAST,
 				       &option, &optlen) < 0)
 				err_sys("IP_ONESBCAST getsockopt error");
 			if (option == 0)
@@ -175,7 +182,7 @@ sockopts(int sockfd, int doall)
 		if (inet_aton(joinip, &join.imr_multiaddr) == 0)
 			err_quit("invalid multicast address: %s", joinip);
 		join.imr_interface.s_addr = htonl(INADDR_ANY);
-		if (setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP,
+		if (setsockopt(sockfd, level, IP_ADD_MEMBERSHIP,
 			       &join, sizeof(join)) < 0)
 			err_sys("IP_ADD_MEMBERSHIP setsockopt error");
 		
@@ -188,12 +195,12 @@ sockopts(int sockfd, int doall)
 	if (mcastttl) {
 		u_char	ttl = mcastttl;
 		
-		if (setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_TTL,
+		if (setsockopt(sockfd, level, IP_MULTICAST_TTL,
 			       &ttl, sizeof(ttl)) < 0)
 			err_sys("IP_MULTICAST_TTL setsockopt error");
 		
 		optlen = sizeof(ttl);
-		if (getsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_TTL,
+		if (getsockopt(sockfd, level, IP_MULTICAST_TTL,
 			       &ttl, &optlen) < 0)
 			err_sys("IP_MULTICAST_TTL getsockopt error");
 		if (ttl != mcastttl)
@@ -288,7 +295,7 @@ sockopts(int sockfd, int doall)
 		
 		if (verbose)
 			fprintf(stderr, "SO_RCVTIMEO: %ld.%06ld\n",
-				timer.tv_sec, timer.tv_usec);
+			    (long)timer.tv_sec, timer.tv_usec);
 #else
 		fprintf(stderr, "warning: SO_RCVTIMEO not supported by host\n");
 #endif
@@ -311,7 +318,7 @@ sockopts(int sockfd, int doall)
 		
 		if (verbose)
 			fprintf(stderr, "SO_SNDTIMEO: %ld.%06ld\n",
-				timer.tv_sec, timer.tv_usec);
+			    (long)timer.tv_sec, timer.tv_usec);
 #else
 		fprintf(stderr, "warning: SO_SNDTIMEO not supported by host\n");
 #endif
@@ -320,13 +327,13 @@ sockopts(int sockfd, int doall)
 	if (recvdstaddr && udp) {
 #ifdef	IP_RECVDSTADDR
 		option = 1;
-		if (setsockopt(sockfd, IPPROTO_IP, IP_RECVDSTADDR,
+		if (setsockopt(sockfd, level, IP_RECVDSTADDR,
 			       &option, sizeof(option)) < 0)
 			err_sys("IP_RECVDSTADDR setsockopt error");
 		
 		option = 0;
 		optlen = sizeof(option);
-		if (getsockopt(sockfd, IPPROTO_IP, IP_RECVDSTADDR,
+		if (getsockopt(sockfd, level, IP_RECVDSTADDR,
 			       &option, &optlen) < 0)
 			err_sys("IP_RECVDSTADDR getsockopt error");
 		if (option == 0)
