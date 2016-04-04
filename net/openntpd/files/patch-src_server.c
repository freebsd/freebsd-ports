--- src/server.c.orig	2016-03-28 13:51:51 UTC
+++ src/server.c
@@ -36,14 +36,14 @@ setup_listeners(struct servent *se, stru
 	struct ifaddrs		*ifa, *ifap;
 	struct sockaddr		*sa;
 #ifdef SO_RTABLE
-	struct if_data		*ifd;
+	struct ifreq		 ifr;
 #endif
 	u_int8_t		*a6;
 	size_t			 sa6len = sizeof(struct in6_addr);
 	u_int			 new_cnt = 0;
 	int			 tos = IPTOS_LOWDELAY;
 #ifdef SO_RTABLE
-	int			 rdomain = 0;
+	int			 rdomain, fd;
 #endif
 
 	TAILQ_FOREACH(lap, &lconf->listen_addrs, entry) {
@@ -56,16 +56,21 @@ setup_listeners(struct servent *se, stru
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
 #ifdef SO_RTABLE
+				strlcpy(ifr.ifr_name, ifap->ifa_name,
+				    sizeof(ifr.ifr_name));
+
+				fd = socket(AF_INET, SOCK_DGRAM, 0);
+				if (ioctl(fd, SIOCGIFRDOMAIN,
+				    (caddr_t)&ifr) == -1)
+					rdomain = 0;
+				else
+					rdomain = ifr.ifr_rdomainid;
+				close(fd);
+
 				if (lap->rtable != -1 && rdomain != lap->rtable)
 					continue;
 #endif
