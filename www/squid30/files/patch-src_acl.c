--- src/acl.c	2004/02/04 05:45:07	1.1
+++ src/acl.c	2004/02/04 05:45:16
@@ -2626,6 +2626,9 @@
 #endif
 #include <net/route.h>
 #include <net/if.h>
+#ifdef _SQUID_FREEBSD__
+#include <net/if_arp.h>
+#endif
 #if HAVE_NETINET_IF_ETHER_H
 #include <netinet/if_ether.h>
 #endif
@@ -2846,6 +2849,82 @@
 	    inet_ntoa(c), splayLastResult ? "NOT found" : "found");
 	return (0 == splayLastResult);
     }
+#elif defined(_SQUID_FREEBSD_)
+    struct arpreq arpReq;
+    struct sockaddr_in ipAddr;
+    unsigned char ifbuffer[sizeof(struct ifreq) * 64];
+    struct ifconf ifc;
+    struct ifreq *ifr;
+    int offset;
+    splayNode **Top = dataptr;
+
+    int mib[6];
+    size_t needed;
+    char *lim, *buf, *next;
+    struct rt_msghdr *rtm;
+    struct sockaddr_inarp *sin;
+    struct sockaddr_dl *sdl;
+
+    /*
+     * Set up structures for ARP lookup with blank interface name
+     */
+    ipAddr.sin_family = AF_INET;
+    ipAddr.sin_port = 0;
+    ipAddr.sin_addr = c;
+    memset(&arpReq, '\0', sizeof(arpReq));
+    xmemcpy(&arpReq.arp_pa, &ipAddr, sizeof(struct sockaddr_in));
+    
+    /* Query ARP table */
+    mib[0] = CTL_NET;
+    mib[1] = PF_ROUTE;
+    mib[2] = 0;
+    mib[3] = AF_INET;
+    mib[4] = NET_RT_FLAGS;
+    mib[5] = RTF_LLINFO;
+    if (sysctl(mib, 6, NULL, &needed, NULL, 0) < 0) {
+	debug(28, 0) ("Can't estimate ARP table size!\n");
+	return 0;
+    }
+    if ((buf = xmalloc(needed)) == NULL) {
+	debug(28, 0) ("Can't allocate temporary ARP table!\n");
+	return 0;
+    }
+    if (sysctl(mib, 6, buf, &needed, NULL, 0) < 0) {
+	debug(28, 0) ("Can't retrieve ARP table!\n");
+	xfree(buf);
+	return 0;
+    }
+    lim = buf + needed;
+    for (next = buf; next < lim; next += rtm->rtm_msglen) {
+        rtm = (struct rt_msghdr *) next;
+        sin = (struct sockaddr_inarp *) (rtm + 1);
+	/*sdl = (struct sockaddr_dl *) (sin + 1);*/
+#define ROUNDUP(a) \
+        ((a) > 0 ? (1 + (((a) - 1) | (sizeof(long) - 1))) : sizeof(long))
+        (char *)sdl = (char *)sin + ROUNDUP(sin->sin_len);
+        if (c.s_addr == sin->sin_addr.s_addr) {
+            if (sdl->sdl_alen)
+            {
+                arpReq.arp_ha.sa_len = sizeof(struct sockaddr);
+                arpReq.arp_ha.sa_family = AF_UNSPEC;
+                memcpy(arpReq.arp_ha.sa_data, LLADDR(sdl), sdl->sdl_alen);
+            }
+	}
+    }
+    xfree(buf);
+    if (arpReq.arp_ha.sa_data[0] == 0 && arpReq.arp_ha.sa_data[1] == 0 &&
+        arpReq.arp_ha.sa_data[2] == 0 && arpReq.arp_ha.sa_data[3] == 0 &&
+        arpReq.arp_ha.sa_data[4] == 0 && arpReq.arp_ha.sa_data[5] == 0)
+        return 0;
+    debug(28, 4) ("Got address %02x:%02x:%02x:%02x:%02x:%02x\n",
+        arpReq.arp_ha.sa_data[0] & 0xff, arpReq.arp_ha.sa_data[1] & 0xff,
+        arpReq.arp_ha.sa_data[2] & 0xff, arpReq.arp_ha.sa_data[3] & 0xff,
+        arpReq.arp_ha.sa_data[4] & 0xff, arpReq.arp_ha.sa_data[5] & 0xff);
+    /* Do lookup */
+    *Top = splay_splay(&arpReq.arp_ha.sa_data, *Top, aclArpCompare);
+    debug(28, 3) ("aclMatchArp: '%s' %s\n",
+        inet_ntoa(c), splayLastResult ? "NOT found" : "found");
+    return (0 == splayLastResult);
 #else
     WRITE ME;
 #endif
@@ -2869,6 +2948,21 @@
     if (d1[2] != d2[2])
 	return (d1[2] > d2[2]) ? 1 : -1;
 #elif defined(_SQUID_SOLARIS_)
+    const unsigned char *d1 = a;
+    const unsigned char *d2 = b;
+    if (d1[0] != d2[0])
+	return (d1[0] > d2[0]) ? 1 : -1;
+    if (d1[1] != d2[1])
+	return (d1[1] > d2[1]) ? 1 : -1;
+    if (d1[2] != d2[2])
+	return (d1[2] > d2[2]) ? 1 : -1;
+    if (d1[3] != d2[3])
+	return (d1[3] > d2[3]) ? 1 : -1;
+    if (d1[4] != d2[4])
+	return (d1[4] > d2[4]) ? 1 : -1;
+    if (d1[5] != d2[5])
+	return (d1[5] > d2[5]) ? 1 : -1;
+#elif defined(_SQUID_FREEBSD_)
     const unsigned char *d1 = a;
     const unsigned char *d2 = b;
     if (d1[0] != d2[0])
