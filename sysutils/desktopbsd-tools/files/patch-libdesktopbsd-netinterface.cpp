--- libdesktopbsd/netinterface.cpp.orig	2007-07-29 09:36:00.000000000 +1100
+++ libdesktopbsd/netinterface.cpp	2008-07-04 17:00:31.000000000 +1100
@@ -22,6 +22,9 @@
 #include <ifaddrs.h>
 #include <net/route.h>
 #include <net/if.h>
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 800038
+#include <net80211/_ieee80211.h>
+#endif
 #include <net80211/ieee80211.h>
 #include <net80211/ieee80211_crypto.h>
 #include <net80211/ieee80211_ioctl.h>
