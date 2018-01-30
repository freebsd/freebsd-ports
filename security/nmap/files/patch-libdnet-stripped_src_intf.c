--- libdnet-stripped/src/intf.c.orig	2016-07-27 20:11:27 UTC
+++ libdnet-stripped/src/intf.c
@@ -163,7 +163,7 @@ intf_open(void)
 #if defined(SIOCGLIFCONF) || defined(SIOCGIFNETMASK_IN6) || defined(SIOCGIFNETMASK6)
 		if ((intf->fd6 = socket(AF_INET6, SOCK_DGRAM, 0)) < 0) {
 #  ifdef EPROTONOSUPPORT
-			if (errno != EPROTONOSUPPORT)
+			if (errno != EPROTONOSUPPORT && errno != EAFNOSUPPORT)
 #  endif
 				return (intf_close(intf));
 		}
