--- panel-plugin/wi_bsd.c.orig	2006-12-21 22:33:39.000000000 +0100
+++ panel-plugin/wi_bsd.c	2008-03-14 16:00:57.000000000 +0100
@@ -1,6 +1,8 @@
 /* $Id: wi_bsd.c 562 2004-12-03 18:29:41Z benny $ */
 /*-
  * Copyright (c) 2003 Benedikt Meurer <benny@xfce.org>
+ *               2008 Pietro Cerutti <gahr@gahr.ch>
+ *                    (FreeBSD > 700000 adaptation)
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted provided that the following conditions
@@ -36,16 +38,19 @@
 #include <net/if.h>
 #include <net/if_media.h>
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#include <netinet/in.h>
+#include <netinet/if_ether.h>
+#include <sys/endian.h>
+#if __FreeBSD_version >= 700000
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <net80211/ieee80211_ioctl.h>
+#else
 #include <net/if_var.h>
 #include <net/ethernet.h>
-
 #include <dev/wi/if_wavelan_ieee.h>
-#if __FreeBSD_version >= 500033
-#include <sys/endian.h>
 #endif
 #else
-#include <netinet/in.h>
-#include <netinet/if_ether.h>
 #ifdef __NetBSD__
 #include <net80211/ieee80211.h>
 #include <net80211/ieee80211_ioctl.h>
@@ -95,7 +100,11 @@
 };
 
 static int _wi_carrier(const struct wi_device *);
+#if defined(__FreeBSD__) && __FreeBSD_version > 700000
+static int _wi_getval(const struct wi_device *, struct ieee80211req_scan_result *);
+#else
 static int _wi_getval(const struct wi_device *, struct wi_req *);
+#endif
 static int _wi_vendor(const struct wi_device *, char *, size_t);
 static int _wi_netname(const struct wi_device *, char *, size_t);
 static int _wi_quality(const struct wi_device *, int *);
@@ -193,24 +202,73 @@
 	return((ifmr.ifm_status & IFM_ACTIVE) != 0 ? WI_OK : WI_NOCARRIER);
 }
 
+#if defined(__FreeBSD__) && __FreeBSD_version >= 700000
 static int
-_wi_getval(const struct wi_device *device, struct wi_req *wr)
+_wi_getval(const struct wi_device *device, struct ieee80211req_scan_result *scan)
 {
-  struct ifreq ifr;
+   char buffer[24 * 1024];
+   const uint8_t *bp;
+   struct ieee80211req ireq;
+   size_t len;
+   bzero(&ireq, sizeof(ireq));
+   strlcpy(ireq.i_name, device->interface, sizeof(ireq.i_name));
+
+   ireq.i_type = IEEE80211_IOC_SCAN_RESULTS;
+   ireq.i_data = buffer;
+   ireq.i_len = sizeof(buffer);
+
+   if(ioctl(device->socket, SIOCG80211, &ireq) < 0)
+      return(WI_NOSUCHDEV);
 
-  bzero((void*)&ifr, sizeof(ifr));
-  strlcpy(ifr.ifr_name, device->interface, sizeof(ifr.ifr_name));
-  ifr.ifr_data = (void*)wr;
+   if(ireq.i_len < sizeof(struct ieee80211req_scan_result))
+      return(WI_NOSUCHDEV);
 
-  if (ioctl(device->socket, SIOCGWAVELAN, &ifr) < 0)
-    return(WI_NOSUCHDEV);
+   memcpy(scan, buffer, sizeof(struct ieee80211req_scan_result));
 
-  return(WI_OK);
+   return(WI_OK);
 }
+#else
+static int
+_wi_getval(const struct wi_device *device, struct wi_req *wr)
+{
+   struct ifreq ifr;
+
+   bzero((void*)&ifr, sizeof(ifr));
+   strlcpy(ifr.ifr_name, device->interface, sizeof(ifr.ifr_name));
+   ifr.ifr_data = (void*)wr;
+
+   if (ioctl(device->socket, SIOCGWAVELAN, &ifr) < 0)
+      return(WI_NOSUCHDEV);
+   
+   return (WI_OK);
+}
+#endif
 
 static int
 _wi_vendor(const struct wi_device *device, char *buffer, size_t len)
 {
+#if defined(__FreeBSD__) && __FreeBSD_version >= 700000
+   /*
+    * We use sysctl to get a device description
+    */
+   char mib[WI_MAXSTRLEN];
+   char dev_name[WI_MAXSTRLEN];
+   char *c = dev_name;
+   int  dev_number;
+
+   /*
+    * Dirty hack to split the device name into name and number
+    */
+   strncpy(dev_name, device->interface, WI_MAXSTRLEN);
+   while(!isdigit(*c)) c++;
+   dev_number = (int)strtol(c, NULL, 10);
+   *c = '\0';
+
+
+   snprintf(mib, sizeof(mib), "dev.%s.%d.%%desc", dev_name, dev_number);
+   if(sysctlbyname(mib, buffer, &len, NULL, 0) == -1)
+      return (WI_NOSUCHDEV);
+#else
 #define WI_RID_STA_IDENTITY_LUCENT	0x1
 #define WI_RID_STA_IDENTITY_PRISMII	0x2
 #define WI_RID_STA_IDENTITY_SAMSUNG	0x3
@@ -250,6 +308,7 @@
 
   snprintf(buffer, len, "%s (ID %d, version %d.%d)", vendor,
       wr.wi_val[0], wr.wi_val[2], wr.wi_val[3]);
+#endif
 
   return(WI_OK);
 }
@@ -257,6 +316,18 @@
 static int
 _wi_netname(const struct wi_device *device, char *buffer, size_t len)
 {
+#if defined(__FreeBSD__) && __FreeBSD_version >= 700000
+   struct ieee80211req ireq;
+
+   memset(&ireq, 0, sizeof(ireq));
+   strncpy(ireq.i_name, device->interface, sizeof(ireq.i_name));
+   ireq.i_type = IEEE80211_IOC_SSID;
+   ireq.i_val = -1;
+   ireq.i_data = buffer;
+   ireq.i_len = len; 
+   if (ioctl(device->socket, SIOCG80211, &ireq) < 0) 
+      return WI_NOSUCHDEV;
+#else
   struct wi_req wr;
   int result;
 
@@ -268,6 +339,7 @@
     return(result);
 
   strlcpy(buffer, (char *)&wr.wi_val[1], MIN(len, le16toh(wr.wi_val[0]) + 1));
+#endif
 
   return(WI_OK);
 }
@@ -275,6 +347,16 @@
 static int
 _wi_quality(const struct wi_device *device, int *quality)
 {
+#if defined(__FreeBSD__) && __FreeBSD_version >= 700000
+   struct ieee80211req_scan_result req;
+   int result;
+   bzero(&req, sizeof(req));
+
+   if((result = _wi_getval(device, &req)) != WI_OK)
+      return (result);
+
+   *quality = req.isr_rssi;
+#else
   struct wi_req wr;
   int result;
 
@@ -289,6 +371,7 @@
     *quality = le16toh(wr.wi_val[1]);
   else
     *quality = le16toh(wr.wi_val[0]);
+#endif
 
   return(WI_OK);
 }
@@ -296,6 +379,20 @@
 static int
 _wi_rate(const struct wi_device *device, int *rate)
 {
+#if defined(__FreeBSD__) && __FreeBSD_version >= 700000
+   struct ieee80211req_scan_result req;
+   int result, i, high;
+   bzero(&req, sizeof(req));
+
+   if((result = _wi_getval(device, &req)) != WI_OK)
+      return (result);
+
+   for(i=0, high=-1; i<req.isr_nrates; i++)
+      if((req.isr_rates[i] & IEEE80211_RATE_VAL) > high)
+         high = req.isr_rates[i] & IEEE80211_RATE_VAL;
+   
+   *rate = high / 2;
+#else
   struct wi_req wr;
   int result;
 
@@ -307,6 +404,7 @@
     return(result);
 
   *rate = le16toh(wr.wi_val[0]);
+#endif
 
   return(WI_OK);
 }
