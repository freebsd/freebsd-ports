--- zebra/if_netlink.c.orig	2018-03-12 00:53:37 UTC
+++ zebra/if_netlink.c
@@ -985,9 +985,11 @@ int netlink_interface_addr(struct sockaddr_nl *snl, st
 			      & (IFA_F_DADFAILED | IFA_F_TENTATIVE)))
 				connected_add_ipv6(ifp, flags,
 						   (struct in6_addr *)addr,
+						   (struct in6_addr *)broad,
 						   ifa->ifa_prefixlen, label);
 		} else
 			connected_delete_ipv6(ifp, (struct in6_addr *)addr,
+					      (struct in6_addr *)broad,
 					      ifa->ifa_prefixlen);
 	}
 
