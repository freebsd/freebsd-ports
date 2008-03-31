--- config.c.orig	1998-01-06 07:57:41.000000000 +0600
+++ config.c	2008-03-30 20:39:31.000000000 +0700
@@ -10,15 +10,13 @@
  * config.c,v 3.8.4.10 1998/01/06 01:57:41 fenner Exp
  */
 
-
-#include "defs.h"
-
 #ifndef lint
-static char rcsid[] = "@(#) $Id: \
-config.c,v 3.8.4.10 1998/01/06 01:57:41 fenner Exp $";
-#endif
+static const char rcsid[] =
+  "$FreeBSD: /tmp/pcvs/ports/net/mrouted/files/Attic/patch-config.c,v 1.1 2008-03-31 10:13:37 bms Exp $";
+#endif /* not lint */
 
-struct ifconf ifc;
+#include "defs.h"
+#include <ifaddrs.h>
 
 /*
  * Query the kernel to find network interfaces that are multicast-capable
@@ -27,94 +25,47 @@
 void
 config_vifs_from_kernel()
 {
-    struct ifreq *ifrp, *ifend;
+    struct ifaddrs *ifa, *ifap;
     register struct uvif *v;
     register vifi_t vifi;
-    int n;
     u_int32 addr, mask, subnet;
-    short flags;
-    int num_ifreq = 32;
-
-    ifc.ifc_len = num_ifreq * sizeof(struct ifreq);
-    ifc.ifc_buf = malloc(ifc.ifc_len);
-    while (ifc.ifc_buf) {
-	if (ioctl(udp_socket, SIOCGIFCONF, (char *)&ifc) < 0)
-	    log(LOG_ERR, errno, "ioctl SIOCGIFCONF");
-
-	/*
-	 * If the buffer was large enough to hold all the addresses
-	 * then break out, otherwise increase the buffer size and
-	 * try again.
-	 *
-	 * The only way to know that we definitely had enough space
-	 * is to know that there was enough space for at least one
-	 * more struct ifreq. ???
-	 */
-	if ((num_ifreq * sizeof(struct ifreq)) >=
-	     ifc.ifc_len + sizeof(struct ifreq))
-	     break;
-
-	num_ifreq *= 2;
-	ifc.ifc_len = num_ifreq * sizeof(struct ifreq);
-	ifc.ifc_buf = realloc(ifc.ifc_buf, ifc.ifc_len);
-    }
-    if (ifc.ifc_buf == NULL)
-	log(LOG_ERR, 0, "config_vifs_from_kernel: ran out of memory");
+    int flags;
 
-    ifrp = (struct ifreq *)ifc.ifc_buf;
-    ifend = (struct ifreq *)(ifc.ifc_buf + ifc.ifc_len);
+    if (getifaddrs(&ifap) < 0)
+	log(LOG_ERR, errno, "getifaddrs");
     /*
      * Loop through all of the interfaces.
      */
-    for (; ifrp < ifend; ifrp = (struct ifreq *)((char *)ifrp + n)) {
-	struct ifreq ifr;
-#ifdef HAVE_SA_LEN
-	n = ifrp->ifr_addr.sa_len + sizeof(ifrp->ifr_name);
-	if (n < sizeof(*ifrp))
-	    n = sizeof(*ifrp);
-#else
-	n = sizeof(*ifrp);
-#endif
+    for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
 	/*
 	 * Ignore any interface for an address family other than IP.
 	 */
-	if (ifrp->ifr_addr.sa_family != AF_INET)
+	if (ifa->ifa_addr->sa_family != AF_INET)
 	    continue;
 
-	addr = ((struct sockaddr_in *)&ifrp->ifr_addr)->sin_addr.s_addr;
-
-	/*
-	 * Need a template to preserve address info that is
-	 * used below to locate the next entry.  (Otherwise,
-	 * SIOCGIFFLAGS stomps over it because the requests
-	 * are returned in a union.)
-	 */
-	bcopy(ifrp->ifr_name, ifr.ifr_name, sizeof(ifr.ifr_name));
+	addr = ((struct sockaddr_in *)ifa->ifa_addr)->sin_addr.s_addr;
 
 	/*
 	 * Ignore loopback interfaces and interfaces that do not support
 	 * multicast.
 	 */
-	if (ioctl(udp_socket, SIOCGIFFLAGS, (char *)&ifr) < 0)
-	    log(LOG_ERR, errno, "ioctl SIOCGIFFLAGS for %s", ifr.ifr_name);
-	flags = ifr.ifr_flags;
-	if ((flags & (IFF_LOOPBACK|IFF_MULTICAST)) != IFF_MULTICAST) continue;
+	flags = ifa->ifa_flags;
+	if ((flags & (IFF_LOOPBACK|IFF_MULTICAST)) != IFF_MULTICAST)
+	    continue;
 
 	/*
 	 * Ignore any interface whose address and mask do not define a
 	 * valid subnet number, or whose address is of the form {subnet,0}
 	 * or {subnet,-1}.
 	 */
-	if (ioctl(udp_socket, SIOCGIFNETMASK, (char *)&ifr) < 0)
-	    log(LOG_ERR, errno, "ioctl SIOCGIFNETMASK for %s", ifr.ifr_name);
-	mask = ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr.s_addr;
+	mask = ((struct sockaddr_in *)ifa->ifa_netmask)->sin_addr.s_addr;
 	subnet = addr & mask;
 	if (!inet_valid_subnet(subnet, mask) ||
 	    addr == subnet ||
 	    addr == (subnet | ~mask)) {
 	    log(LOG_WARNING, 0,
 		"ignoring %s, has invalid address (%s) and/or mask (%s)",
-		ifr.ifr_name, inet_fmt(addr, s1), inet_fmt(mask, s2));
+		ifa->ifa_name, inet_fmt(addr, s1), inet_fmt(mask, s2));
 	    continue;
 	}
 
@@ -123,7 +74,7 @@
 	 * one already installed in the uvifs array.
 	 */
 	for (vifi = 0, v = uvifs; vifi < numvifs; ++vifi, ++v) {
-	    if (strcmp(v->uv_name, ifr.ifr_name) == 0) {
+	    if (strcmp(v->uv_name, ifa->ifa_name) == 0) {
 		log(LOG_DEBUG, 0, "skipping %s (%s on subnet %s) (alias for vif#%u?)",
 			v->uv_name, inet_fmt(addr, s1),
 			inet_fmts(subnet, mask, s2), vifi);
@@ -132,7 +83,7 @@
 	    if ((addr & v->uv_subnetmask) == v->uv_subnet ||
 		(v->uv_subnet & mask) == subnet) {
 		log(LOG_WARNING, 0, "ignoring %s, same subnet as %s",
-					ifr.ifr_name, v->uv_name);
+		    ifa->ifa_name, v->uv_name);
 		break;
 	    }
 	}
@@ -142,7 +93,7 @@
 	 * If there is room in the uvifs array, install this interface.
 	 */
 	if (numvifs == MAXVIFS) {
-	    log(LOG_WARNING, 0, "too many vifs, ignoring %s", ifr.ifr_name);
+	    log(LOG_WARNING, 0, "too many vifs, ignoring %s", ifa->ifa_name);
 	    continue;
 	}
 	v  = &uvifs[numvifs];
@@ -151,7 +102,7 @@
 	v->uv_subnet      = subnet;
 	v->uv_subnetmask  = mask;
 	v->uv_subnetbcast = subnet | ~mask;
-	strncpy(v->uv_name, ifr.ifr_name, IFNAMSIZ);
+	strlcpy(v->uv_name, ifa->ifa_name, sizeof(v->uv_name));
 
 	if (flags & IFF_POINTOPOINT)
 	    v->uv_flags |= VIFF_REXMIT_PRUNES;
@@ -171,4 +122,6 @@
 	    vifs_down = TRUE;
 	}
     }
+
+    freeifaddrs(ifap);
 }
