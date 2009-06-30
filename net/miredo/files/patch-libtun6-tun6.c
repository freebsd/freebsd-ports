diff --git libtun6/tun6.c libtun6/tun6.c
index c0e37ba..a9a3c4c 100644
--- libtun6/tun6.c
+++ libtun6/tun6.c
@@ -81,6 +81,7 @@ typedef struct
       defined (__OpenBSD__) || defined (__OpenBSD_kernel__) || \
       defined (__DragonFly__) || \
       defined (__APPLE__) /* Darwin */
+#include <ifaddrs.h>
 /*
  * BSD tunneling driver
  * NOTE: the driver is NOT tested on Darwin (Mac OS X).
@@ -492,8 +493,7 @@ plen_to_sin6 (unsigned plen, struct sockaddr_in6 *sin6)
 {
 	memset (sin6, 0, sizeof (struct sockaddr_in6));
 
-	/* NetBSD kernel strangeness:
-	 sin6->sin6_family = AF_INET6;*/
+	sin6->sin6_family = AF_INET6;
 # ifdef HAVE_SA_LEN
 	sin6->sin6_len = sizeof (struct sockaddr_in6);
 # endif
@@ -636,8 +636,8 @@ _iface_route (int reqfd, int id, bool add, const struct in6_addr *addr,
 	{
 		struct rt_msghdr hdr;
 		struct sockaddr_in6 dst;
-		struct sockaddr_dl gw;
-		struct sockaddr_in6 mask;
+		struct sockaddr_storage gw;
+		struct sockaddr_storage dummy; /* allocate space for netmask */
 	} msg;
 
 	shutdown (s, 0);
@@ -661,11 +661,31 @@ _iface_route (int reqfd, int id, bool add, const struct in6_addr *addr,
 	msg.dst.sin6_len = sizeof (msg.dst);
 	memcpy (&msg.dst.sin6_addr, addr, sizeof (msg.dst.sin6_addr));
 
-	msg.gw.sdl_family = AF_LINK;
-	msg.gw.sdl_len = sizeof (msg.gw);
-	msg.gw.sdl_index = id;
+	struct ifaddrs *ifap, *ifa;
+	struct sockaddr_dl *sdl = NULL;
 
-	plen_to_sin6 (prefix_len, &msg.mask);
+	if (getifaddrs(&ifap)) {
+		syslog (LOG_ERR, "getifaddrs erorr\n");
+		return -1;
+	}
+	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
+		if (ifa->ifa_addr == NULL)
+			continue;
+		if (ifa->ifa_addr->sa_family != AF_LINK)
+			continue;
+		if (id == ((struct sockaddr_dl *)ifa->ifa_addr)->sdl_index)
+			sdl = (struct sockaddr_dl *)ifa->ifa_addr;
+	}
+	if (sdl == NULL) {
+		syslog (LOG_ERR, "no sdl found\n");
+		freeifaddrs(ifap);
+		return -1;
+	}
+	memcpy(&msg.gw, sdl, sdl->sdl_len);
+	freeifaddrs(ifap);
+
+	struct sockaddr_in6 *mask = (struct sockaddr_in6 *)((u_char *)&msg.gw + sdl->sdl_len);
+	plen_to_sin6 (prefix_len, mask);
 
 	errno = 0;
 
@@ -678,6 +698,8 @@ _iface_route (int reqfd, int id, bool add, const struct in6_addr *addr,
 "There is probably another tunnel with a conflicting route present\n"
 "(see also FreeBSD PR kern/100080).\n"
 "Please upgrade to FreeBSD 6.3 or more recent to fix this.\n");
+	else syslog (LOG_NOTICE,
+"Creating a route erorr: %s\n", strerror (errno));
 
 	(void)close (s);
 #else
