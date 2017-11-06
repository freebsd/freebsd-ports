--- libdnet-stripped/src/intf.c.orig	2017-03-05 16:19:13.768984000 +0700
+++ libdnet-stripped/src/intf.c	2017-03-05 16:16:48.337379000 +0700
@@ -163,7 +163,7 @@ intf_open(void)
 #if defined(SIOCGLIFCONF) || defined(SIOCGIFNETMASK_IN6) || defined(SIOCGIFNETMASK6)
 		if ((intf->fd6 = socket(AF_INET6, SOCK_DGRAM, 0)) < 0) {
 #  ifdef EPROTONOSUPPORT
-			if (errno != EPROTONOSUPPORT)
+			if (errno != EPROTONOSUPPORT && errno != EAFNOSUPPORT)
 #  endif
 				return (intf_close(intf));
 		}
