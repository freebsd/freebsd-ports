https://bugzilla.samba.org/show_bug.cgi?id=9666

--- ./lib/socket/interfaces.c.orig	2012-10-02 08:24:40.000000000 +0000
+++ ./lib/socket/interfaces.c	2013-02-18 06:52:41.529874139 +0000
@@ -185,7 +185,22 @@
 
 		memcpy(&ifaces[total].ip, ifptr->ifa_addr, copy_size);
 		memcpy(&ifaces[total].netmask, ifptr->ifa_netmask, copy_size);
+		/* calculate broadcast address */
+#if defined(HAVE_IPV6)
+		if (ifptr->ifa_addr->sa_family == AF_INET6) {
+			struct sockaddr_in6 *sin6 =
+				(struct sockaddr_in6 *)ifptr->ifa_addr;
+			struct in6_addr *in6 =
+				(struct in6_addr *)&sin6->sin6_addr;
 
+			if (IN6_IS_ADDR_LINKLOCAL(in6) || IN6_IS_ADDR_V4COMPAT(in6)) {
+				sin6->sin6_scope_id = if_nametoindex(ifptr->ifa_name);
+				continue;
+			}
+			/* IPv6 does not have broadcast it uses multicast. */
+			memset(&ifaces[total].bcast, '\0', copy_size);
+		} else
+#endif
 		if (ifaces[total].flags & (IFF_BROADCAST|IFF_LOOPBACK)) {
 			make_bcast(&ifaces[total].bcast,
 				&ifaces[total].ip,
@@ -195,20 +210,8 @@
 			memcpy(&ifaces[total].bcast,
 				ifptr->ifa_dstaddr,
 				copy_size);
-#if defined(HAVE_IPV6)
-		} else if (ifptr->ifa_addr->sa_family == AF_INET6) {
-			const struct sockaddr_in6 *sin6 =
-				(const struct sockaddr_in6 *)ifptr->ifa_addr;
-			const struct in6_addr *in6 =
-				(const struct in6_addr *)&sin6->sin6_addr;
-
-			if (IN6_IS_ADDR_LINKLOCAL(in6) || IN6_IS_ADDR_V4COMPAT(in6)) {
-				continue;
-			}
-			/* IPv6 does not have broadcast it uses multicast. */
-			memset(&ifaces[total].bcast, '\0', copy_size);
-#endif
-		} else {
+		}
+		else {
 			continue;
 		}
 
