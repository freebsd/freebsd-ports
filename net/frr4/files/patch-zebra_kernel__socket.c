--- zebra/kernel_socket.c.orig	2018-03-12 00:53:37 UTC
+++ zebra/kernel_socket.c
@@ -771,10 +771,11 @@ int ifam_read(struct ifa_msghdr *ifam)
 
 		if (ifam->ifam_type == RTM_NEWADDR)
 			connected_add_ipv6(ifp, flags, &addr.sin6.sin6_addr,
+					   NULL,
 					   ip6_masklen(mask.sin6.sin6_addr),
 					   (isalias ? ifname : NULL));
 		else
-			connected_delete_ipv6(ifp, &addr.sin6.sin6_addr,
+			connected_delete_ipv6(ifp, &addr.sin6.sin6_addr, NULL,
 					      ip6_masklen(mask.sin6.sin6_addr));
 		break;
 	default:
