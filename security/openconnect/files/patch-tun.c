--- tun.c.orig	2011-11-24 08:18:34.000000000 -0800
+++ tun.c	2012-03-12 22:46:30.000000000 -0700
@@ -38,6 +38,9 @@
 #include <arpa/inet.h>
 #include <errno.h>
 #include <ctype.h>
+#if defined(__FreeBSD__)
+#include <sys/param.h>	/* For __FreeBSD_version */
+#endif
 #if defined(__sun__)
 #include <stropts.h>
 #include <sys/sockio.h>
@@ -109,9 +112,43 @@
 
 		addr.sin_family = AF_INET;
 		addr.sin_addr.s_addr = inet_addr(vpninfo->vpn_addr);
+
+		/*
+		 * SIOCSIFADDR ioctl was dropped in FreeBSD 10.0
+		 */
+#if defined(__FreeBSD__) && __FreeBSD_version > 1000004
+		{
+			struct ifaliasreq ifra;
+			struct sockaddr_in *sin;
+
+			memset(&ifra, 0, sizeof(ifra));
+			strncpy(ifra.ifra_name, vpninfo->ifname, sizeof(ifra.ifra_name) - 1);
+
+			/* Set source address. */
+			sin = (struct sockaddr_in *)&(ifra.ifra_addr);
+			memcpy(sin, &addr, sizeof(struct sockaddr_in));
+			sin->sin_len = sizeof(*sin);
+
+			/* Set destination address. */
+			sin = (struct sockaddr_in *)&(ifra.ifra_broadaddr);
+			memcpy(sin, &addr, sizeof(struct sockaddr_in));
+			sin->sin_len = sizeof(*sin);
+
+			/* Set mask address. */
+			sin = (struct sockaddr_in *)&(ifra.ifra_mask);
+			addr.sin_family = AF_INET;
+			addr.sin_addr.s_addr = 0xffffffff;
+			memcpy(sin, &addr, sizeof(struct sockaddr_in));
+			sin->sin_len = sizeof(*sin);
+
+			if (ioctl(net_fd, SIOCAIFADDR, &ifra) < 0)
+				perror(_("SIOCAIFADDR"));
+		}
+#else
 		memcpy(&ifr.ifr_addr, &addr, sizeof(addr));
 		if (ioctl(net_fd, SIOCSIFADDR, &ifr) < 0)
 			perror(_("SIOCSIFADDR"));
+#endif
 	}
 
 	ifr.ifr_mtu = vpninfo->mtu;
