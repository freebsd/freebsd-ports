--- libdnet-stripped/src/intf.c.orig	2025-03-31 12:30:47.000000000 -0700
+++ libdnet-stripped/src/intf.c	2026-02-02 15:34:47.918928000 -0800
@@ -178,7 +178,7 @@
 #if defined(SIOCGLIFCONF) || defined(SIOCGIFNETMASK_IN6) || defined(SIOCGIFNETMASK6)
 		if ((intf->fd6 = socket(AF_INET6, SOCK_DGRAM, 0)) < 0) {
 #  ifdef EPROTONOSUPPORT
-			if (errno != EPROTONOSUPPORT)
+			if (errno != EPROTONOSUPPORT && errno != EAFNOSUPPORT)
 #endif
 				return (intf_close(intf));
 		}
