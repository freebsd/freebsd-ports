--- zebra/if_ioctl.c.orig	2018-03-12 00:53:37 UTC
+++ zebra/if_ioctl.c
@@ -249,7 +249,7 @@ static int if_getaddrs(void)
 			}
 #endif
 
-			connected_add_ipv6(ifp, flags, &addr->sin6_addr,
+			connected_add_ipv6(ifp, flags, &addr->sin6_addr, NULL,
 					   prefixlen, NULL);
 		}
 	}
