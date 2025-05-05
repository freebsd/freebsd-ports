--- libdnet-stripped/src/intf.c.orig	2025-04-30 19:58:18 UTC
+++ libdnet-stripped/src/intf.c
@@ -178,7 +178,7 @@ intf_open(void)
 #if defined(SIOCGLIFCONF) || defined(SIOCGIFNETMASK_IN6) || defined(SIOCGIFNETMASK6)
 		if ((intf->fd6 = socket(AF_INET6, SOCK_DGRAM, 0)) < 0) {
 #  ifdef EPROTONOSUPPORT
-			if (errno != EPROTONOSUPPORT)
+			if (errno != EPROTONOSUPPORT && errno != EAFNOSUPPORT)
 #endif
 				return (intf_close(intf));
 		}
