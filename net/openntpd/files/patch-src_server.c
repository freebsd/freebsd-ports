--- src/server.c.orig	2016-05-30 22:50:02 UTC
+++ src/server.c
@@ -35,8 +35,8 @@ setup_listeners(struct servent *se, stru
 	struct listen_addr	*la, *nla, *lap;
 	struct ifaddrs		*ifa, *ifap;
 	struct sockaddr		*sa;
-#ifdef SO_RTABLE
-	struct if_data		*ifd;
+#ifdef SO_SETFIB
+	struct ifreq		 ifr;
 #endif
 	u_int8_t		*a6;
 	size_t			 sa6len = sizeof(struct in6_addr);
@@ -45,8 +45,8 @@ setup_listeners(struct servent *se, stru
 #ifdef IPV6_V6ONLY
 	int			 on = 1;
 #endif
-#ifdef SO_RTABLE
-	int			 rdomain = 0;
+#ifdef SO_SETFIB
+	int			 rdomain, fd;
 #endif
 
 	TAILQ_FOREACH(lap, &lconf->listen_addrs, entry) {
@@ -59,16 +59,20 @@ setup_listeners(struct servent *se, stru
 				sa = ifap->ifa_addr;
 				if (sa == NULL || SA_LEN(sa) == 0)
 					continue;
-#ifdef SO_RTABLE
-				if (sa->sa_family == AF_LINK) {
-					ifd = ifap->ifa_data;
-					rdomain = ifd->ifi_rdomain;
-				}
-#endif
 				if (sa->sa_family != AF_INET &&
 				    sa->sa_family != AF_INET6)
 					continue;
-#ifdef SO_RTABLE
+#ifdef SO_SETFIB
+				strlcpy(ifr.ifr_name, ifap->ifa_name,
+				    sizeof(ifr.ifr_name));
+
+				fd = socket(AF_INET, SOCK_DGRAM, 0);
+				if (ioctl(fd, SIOCGIFFIB, (caddr_t)&ifr) == -1)
+					rdomain = 0;
+				else
+					rdomain = ifr.ifr_fib;
+				close(fd);
+
 				if (lap->rtable != -1 && rdomain != lap->rtable)
 					continue;
 #endif
@@ -90,7 +94,7 @@ setup_listeners(struct servent *se, stru
 					fatal("setup_listeners calloc");
 
 				memcpy(&la->sa, sa, SA_LEN(sa));
-#ifdef SO_RTABLE
+#ifdef SO_SETFIB
 				la->rtable = rdomain;
 #endif
 
@@ -143,11 +147,11 @@ setup_listeners(struct servent *se, stru
 			log_warn("setsockopt IPV6_V6ONLY");
 #endif
 
-#ifdef SO_RTABLE
+#ifdef SO_SETFIB
 		if (la->rtable != -1 &&
-		    setsockopt(la->fd, SOL_SOCKET, SO_RTABLE, &la->rtable,
+		    setsockopt(la->fd, SOL_SOCKET, SO_SETFIB, &la->rtable,
 		    sizeof(la->rtable)) == -1)
-			fatal("setup_listeners setsockopt SO_RTABLE");
+			fatal("setup_listeners setsockopt SO_SETFIB");
 #endif
 
 		if (bind(la->fd, (struct sockaddr *)&la->sa,
