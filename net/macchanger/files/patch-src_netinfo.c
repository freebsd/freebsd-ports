--- src/netinfo.c	2014-01-01 19:10:25.000000000 +0200
+++ src/netinfo.c	2014-10-22 05:49:50.129320393 +0300
@@ -23,14 +23,31 @@
  * USA
  */
 
+#ifdef HAVE_CONFIG_H
+# include <config.h>
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/socket.h>
 #include <sys/ioctl.h>
 
-#include <linux/ethtool.h>
-#include <linux/sockios.h>
+#include <net/if.h>
+#include <ifaddrs.h>
+#include <net/ethernet.h>
+
+#if defined(HAVE_IF_PACKET)
+# include <linux/if_packet.h>
+#elif defined(HAVE_IF_DL)
+# include <net/if_dl.h>
+#endif
+
+#if defined(HAVE_ETHTOOL)
+# include <linux/ethtool.h>
+# include <linux/sockios.h>
+#endif
 
 #include "netinfo.h"
 
@@ -49,7 +66,7 @@
 
 	strncpy (new->dev.ifr_name, device, sizeof(new->dev.ifr_name));
 	new->dev.ifr_name[sizeof(new->dev.ifr_name)-1] = '\0';
-	if (ioctl(new->sock, SIOCGIFHWADDR, &new->dev) < 0) {
+	if (if_nametoindex(device) == 0) {
 		perror ("[ERROR] Set device name");
 		free(new);
 		return NULL;
@@ -66,29 +83,55 @@
 	free(net);
 }
 
-
 mac_t *
 mc_net_info_get_mac (const net_info_t *net)
 {
-	int    i;
-	mac_t *new = (mac_t *) malloc (sizeof(mac_t));
+	int i;
+	mac_t *mac = (mac_t *) malloc (sizeof(mac_t));
+	u_char *lladr;
 
-	for (i=0; i<6; i++) {
-		new->byte[i] = net->dev.ifr_hwaddr.sa_data[i] & 0xFF;
-	}
+	struct ifaddrs *ifap, *ifa;
+	struct sockaddr_ll *sdl;
 
-	return new;
-}
+	if (getifaddrs(&ifap) == 0) {
+		for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
+
+			sdl = (struct sockaddr_ll *) ifa->ifa_addr;
+
+			if (strcmp(ifa->ifa_name, net->dev.ifr_name) != 0)
+				continue;
 
+			if (!sdl && sdl->sll_family != AF_PACKET)
+				continue;
+
+			lladr = (u_char *) LLADDR(sdl);
+			for (i=0; i<6; i++)
+				mac->byte[i] = lladr[i] & 0xFF;
+			break;
+		}
+		freeifaddrs(ifap);
+	} else
+		perror("getifaddrs");
+
+	return mac;
+}
 
 int
 mc_net_info_set_mac (net_info_t *net, const mac_t *mac)
 {
 	int i;
+#if defined(HAVE_ETHTOOL)
+	if (ioctl(net->sock, SIOCGIFHWADDR, &net->dev) < 0) {
+		perror ("[ERROR] Set ifreq structure");
+		return -1;
+	}
+#elif defined(HAVE_SOCKADDR_SA_LEN)
+	net->dev.ifr_addr.sa_family = AF_PACKET;
+	net->dev.ifr_addr.sa_len    = ETHER_ADDR_LEN;
+#endif
 
-	for (i=0; i<6; i++) {
+	for (i=0; i<6; i++)
 		net->dev.ifr_hwaddr.sa_data[i] = mac->byte[i];
-	}
 
 	if (ioctl(net->sock, SIOCSIFHWADDR, &net->dev) < 0) {
 		perror ("[ERROR] Could not change MAC: interface up or insufficient permissions");
@@ -98,6 +141,7 @@
 	return 0;
 }
 
+#if defined(HAVE_ETHTOOL)
 mac_t *
 mc_net_info_get_permanent_mac (const net_info_t *net)
 {
@@ -126,3 +170,4 @@
 	free(epa);
 	return newmac;
 }
+#endif
