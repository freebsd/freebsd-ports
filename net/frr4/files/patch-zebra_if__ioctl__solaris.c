--- zebra/if_ioctl_solaris.c.orig	2018-03-12 00:53:37 UTC
+++ zebra/if_ioctl_solaris.c
@@ -315,7 +315,7 @@ static int if_get_addr(struct interface *ifp, struct s
 		connected_add_ipv4(ifp, flags, &SIN(addr)->sin_addr, prefixlen,
 				   (struct in_addr *)dest_pnt, label);
 	else if (af == AF_INET6)
-		connected_add_ipv6(ifp, flags, &SIN6(addr)->sin6_addr,
+		connected_add_ipv6(ifp, flags, &SIN6(addr)->sin6_addr, NULL,
 				   prefixlen, label);
 
 	return 0;
