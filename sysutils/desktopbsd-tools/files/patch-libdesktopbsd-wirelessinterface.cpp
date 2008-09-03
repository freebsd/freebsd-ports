--- libdesktopbsd/wirelessinterface.cpp.orig	2007-09-02 21:21:11.000000000 +1100
+++ libdesktopbsd/wirelessinterface.cpp	2008-07-04 17:02:25.000000000 +1100
@@ -76,6 +76,8 @@
 
 #include "wirelessinterface.h"
 
+#include <sys/param.h> /* __FreeBSD_version */
+
 #include <net/ethernet.h>
 #include <net/if_dl.h>
 #include <net/if_types.h>
@@ -86,6 +88,9 @@
 #include <ifaddrs.h>
 #include <net/route.h>
 #include <net/if.h>
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 800038
+#include <net80211/_ieee80211.h>
+#endif
 #include <net80211/ieee80211.h>
 #include <net80211/ieee80211_crypto.h>
 #include <net80211/ieee80211_ioctl.h>
