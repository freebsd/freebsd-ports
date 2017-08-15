--- src/wireless.c.orig	2004-03-09 19:39:17 UTC
+++ src/wireless.c
@@ -25,7 +25,13 @@
 #include <net/if_mib.h>
 #include <net/if_var.h>
 #include <netinet/in.h>
+#include <sys/param.h>
+#if __FreeBSD_version > 700045
+#include <net80211/ieee80211.h>
+#include <net80211/ieee80211_ioctl.h>
+#else
 #include <dev/wi/if_wavelan_ieee.h>
+#endif
 #else
 #error "sorry, your OS is not supported yet"
 #endif
@@ -138,11 +144,13 @@ int get_wlaniface(int old, int dir)
 	int i, max, step, found, index;
 	struct ifmibdata ifmd;
 	struct ifmediareq ifmr;
-	int name[6], len, s;
+	int name[6], s;
+	size_t len;
 	char *iface[IFNAMSIZ];
 
 	max = get_max_ifs();
 	step = 0;
+	found = 0;
 
 	if (old > max)
 		old = max; /* just be sure to not be out of bounds */
@@ -178,8 +186,8 @@ int get_wlaniface(int old, int dir)
 		len = sizeof(ifmd);
 		sysctl(name, 6, &ifmd, &len, NULL, 0);
 
-		/* skip loopback interface */
-		if (!strcmp(ifmd.ifmd_name, "lo0"))
+		/* skip loopback and point-to-point interfaces */
+		if ((ifmd.ifmd_flags&(IFF_LOOPBACK|IFF_POINTOPOINT))!=0)
 			continue;
 
 		s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
@@ -193,9 +201,11 @@ int get_wlaniface(int old, int dir)
 
 		if (ioctl(s, SIOCGIFMEDIA, (caddr_t) &ifmr) < 0)
 		{
-			perror("ioctl");
+			char str[128];
+			snprintf(str, 128, "ioctl for interface %s failed", ifmr.ifm_name);
 			close(s);
-			exit(1);
+			warn(str);
+			continue;
 		}
 		close(s);
 		/* we cannot monitor interfaces in hostap mode, so just
@@ -207,12 +217,17 @@ int get_wlaniface(int old, int dir)
 			found++;
 		}
 	}
+
+	if (!found)
+	  return -1;
+
 	return index;
 }
 /* how many interfaces do we have? this includes non-wireless! */
 int get_max_ifs(void)
 {
-	int count, len;
+	int count;
+	size_t len;
 
 	len = sizeof(count);
 	sysctlbyname("net.link.generic.system.ifcount", &count, &len, NULL, 0);
@@ -220,13 +235,23 @@ int get_max_ifs(void)
 }
 int wifi_info(struct wifi *wfi)
 {
-	int name[6], len;		/* interface name */
+	int name[6];			/* interface name */
+	size_t len;
 	struct ifmibdata ifmd;
 
 	struct ifreq ifr;		/* interface stats */
+#if __FreeBSD_version > 700045
+	uint8_t buf[24*1024];
+	struct ieee80211req ireq;
+	const struct ieee80211req_scan_result *sr;
+#else
 	struct wi_req wireq;
+#endif
 	int s;
 
+	wfi->link = 0;
+	wfi->max_qual = 128;
+
 	/* lets find the current interface name */
 	name[0] = CTL_NET;
 	name[1] = PF_LINK;
@@ -247,13 +272,38 @@ int wifi_info(struct wifi *wfi)
 		perror("socket");
 		exit(1);
 	}
-	bzero(&ifr, sizeof(ifr));
 	/* struct ifreq interface name can only be 16 Bytes long as of now */
 	if (strlen(wfi->ifname) >= IFNAMSIZ)
 	{
 		fprintf(stderr, "ERROR: interface name too long\n");
 		exit(1);
 	}
+#if __FreeBSD_version > 700045
+	bzero(&ireq, sizeof(ireq));
+	strncpy(ireq.i_name, wfi->ifname, sizeof(ireq.i_name));
+
+	ireq.i_type = IEEE80211_IOC_SCAN_RESULTS;
+	ireq.i_data = buf;
+	ireq.i_len = sizeof(buf);
+	if (ioctl(s, SIOCG80211, &ireq) < 0) {
+		perror("ioctl");
+		exit(1);
+	}
+	close (s);
+
+	if (ireq.i_len < sizeof(struct ieee80211req_scan_result)) {
+		return 1;
+	}
+
+	sr = (const struct ieee80211req_scan_result *) buf;
+
+	/*
+	 * sr->isr_rssi   Signal Strength
+	 * sr->isr_noise  Noise
+	 */
+	wfi->link = (int) sr->isr_rssi;
+#else
+	bzero(&ifr, sizeof(ifr));
 	strncpy(ifr.ifr_name, wfi->ifname, strlen(wfi->ifname));
 	wireq.wi_type	= WI_RID_COMMS_QUALITY;
 	wireq.wi_len	= WI_MAX_DATALEN;
@@ -272,7 +322,7 @@ int wifi_info(struct wifi *wfi)
 	 * wi_val[2] = noise
 	 */
 	wfi->link = (int) wireq.wi_val[1];
-	wfi->max_qual = 128;
+#endif
 
 	return 1;	
 }
