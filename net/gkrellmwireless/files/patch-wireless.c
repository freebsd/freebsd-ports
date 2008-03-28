--- wireless.c.orig	2001-09-09 16:25:40.000000000 +0200
+++ wireless.c	2008-03-18 12:10:36.000000000 +0100
@@ -94,6 +94,37 @@
 
 static int
 find_wi_card(void) {
+	 int s, ret;
+	 ret =  FALSE;
+
+#if defined(__FreeBSD__) && __FreeBSD_version >= 600034
+  struct ifaddrs *res = NULL, *ifa = NULL;
+  struct ifmediareq ifmr;
+
+  if (getifaddrs(&res))
+		return ret;
+
+  if ((s = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
+		freeifaddrs(res);
+		return ret;
+  }
+
+  for (ifa = res; ifa; ifa = ifa->ifa_next) {
+		memset(&ifmr, 0, sizeof(ifmr));
+		strncpy(ifmr.ifm_name, ifa->ifa_name, sizeof(ifmr.ifm_name));
+		if (ioctl(s, SIOCGIFMEDIA, (caddr_t)&ifmr) < 0)
+			 continue;
+		if (!(ifmr.ifm_status & IFM_AVALID))
+			 continue;
+		if (IFM_TYPE(ifmr.ifm_active) != IFM_IEEE80211)
+			 continue;
+		if (found_wcard(ifa->ifa_name) != NULL)
+			 ret = TRUE;
+  }
+
+  freeifaddrs(res);
+
+#else
   /* possible interfaces */
   char interfaces[][4] = {"wi0","wi1","wi2"};
 
@@ -101,9 +132,8 @@
   struct wi_req wreq;
   /* interface request struct */
   struct ifreq ifr;
-  int s,i,ret;
+  int i;
 
-  ret = FALSE;
   /* open a socket for ioctl's */
   if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == -1) return ret; 
 
@@ -126,7 +156,7 @@
      
     if(found_wcard(interfaces[i]) != NULL) ret = TRUE;
   }
-
+#endif
   close(s);
   return ret;
 }
@@ -174,11 +204,36 @@
 
 static int
 get_wi_link_quality(wcard_t *card, float *quality, float *level, float *noise) {
+  int s;
+#if defined(__FreeBSD__) && __FreeBSD_version >= 600034
+  uint8_t buf[24 * 1024];
+  struct ieee80211req ireq;
+  struct ieee80211req_scan_result *sr;
+
+  if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == -1) return FALSE;
+
+  memset(&ireq, 0, sizeof(ireq));
+  strncpy(ireq.i_name, card->ifname, sizeof(ireq.i_name));
+  ireq.i_type = IEEE80211_IOC_SCAN_RESULTS;
+  ireq.i_data = buf;
+  ireq.i_len = sizeof(buf);
+  if (ioctl(s, SIOCG80211, &ireq) < 0) {
+      close(s);
+      return FALSE;
+  }
+  close(s);
+  if (ireq.i_len < sizeof(struct ieee80211req_scan_result))
+      return FALSE;
+
+  sr = (struct ieee80211req_scan_result *) buf;
+  *quality = sr->isr_intval;
+  *level = sr->isr_rssi;
+  *noise = sr->isr_noise;
+#else
   /* wireless info request struct */
   struct wi_req wreq;
   /* interface request struct */
   struct ifreq ifr;
-  int s;
 
   /* open a socket for ioctl's */
   if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == -1) return FALSE; 
@@ -207,6 +262,8 @@
  *level = wreq.wi_val[1];
  *noise = wreq.wi_val[2];
 
+#endif
+
  return TRUE;
 }
 
