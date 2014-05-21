--- ./panel-plugin/wi_bsd.c.orig	2012-04-09 16:45:20.000000000 +0000
+++ ./panel-plugin/wi_bsd.c	2014-05-20 21:29:11.000000000 +0000
@@ -3,6 +3,8 @@
  *                    (OpenBSD support)
  *               2008 Pietro Cerutti <gahr@gahr.ch>
  *                    (FreeBSD > 700000 adaptation)
+ *               2014 J.R. Oldroyd <fbsd@opal.com> 
+ *                    (Enhance FreeBSD support)
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted provided that the following conditions
@@ -26,14 +28,9 @@
  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
-#if !defined(__FreeBSD_kernel__) && defined(__FreeBSD__)
-#define __FreeBSD_kernel__ __FreeBSD__
-#endif
-#if !defined(__FreeBSD_kernel_version) && defined(__FreeBSD_version)
-#define __FreeBSD_kernel_version __FreeBSD_version
-#endif
+#include <sys/param.h>
 
-#if defined(__NetBSD__) || defined(__FreeBSD_kernel__) || defined(__FreeBSD_kernel_kernel__) || defined(__OpenBSD__) 
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) 
 
 #include <sys/types.h>
 #include <sys/cdefs.h>
@@ -44,20 +41,14 @@
 
 #include <net/if.h>
 #include <net/if_media.h>
-#ifdef __FreeBSD_kernel__
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #include <netinet/in.h>
 #include <netinet/if_ether.h>
 #include <sys/endian.h>
-#if __FreeBSD_kernel_version >= 700000
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <net80211/ieee80211_ioctl.h>
 #else
-#include <net/if_var.h>
-#include <net/ethernet.h>
-#include <dev/wi/if_wavelan_ieee.h>
-#endif
-#else
 #ifdef __NetBSD__
 #include <net80211/ieee80211.h>
 #include <net80211/ieee80211_ioctl.h>
@@ -107,13 +98,9 @@
 };
 
 static int _wi_carrier(const struct wi_device *);
-#if defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 static int _wi_vendor(const struct wi_device *, char *, size_t);
-#if __FreeBSD_kernel_version > 700000
 static int _wi_getval(const struct wi_device *, struct ieee80211req_scan_result *);
-#else
-static int _wi_getval(const struct wi_device *, struct wi_req *);
-#endif
 #endif
 static int _wi_netname(const struct wi_device *, char *, size_t);
 static int _wi_quality(const struct wi_device *, int *);
@@ -160,7 +147,7 @@
 
   strlcpy(stats->ws_qunit, "dBm", 4);
   /* check vendor (independent of carrier state) */
-#if defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
   if ((result = _wi_vendor(device, stats->ws_vendor, WI_MAXSTRLEN)) != WI_OK)
     return(result);
 #endif
@@ -294,12 +281,10 @@
 }
 #endif
 
-/* seems only FreeBSD supports this operation */
-#if defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 static int
 _wi_vendor(const struct wi_device *device, char *buffer, size_t len)
 {
-#if defined(__FreeBSD_kernel__) && __FreeBSD_kernel_version >= 700000
    /*
     * We use sysctl to get a device description
     */
@@ -316,59 +301,30 @@
    dev_number = (int)strtol(c, NULL, 10);
    *c = '\0';
 
+   /*
+    * Also, wlan doesn't present dev.wlan.N.%desc, need to use
+    * underlying driver name, instead: dev.ath.0.%desc, so we
+    * need to get the parent's name.
+    */
+   if(strcmp(dev_name, "wlan") == 0) {
+      snprintf(mib, sizeof(mib), "net.%s.%d.%%parent", dev_name, dev_number);
+      if(sysctlbyname(mib, dev_name, &len, NULL, 0) == -1)
+         return (WI_NOSUCHDEV);
+
+      c = dev_name;
+      while(!isdigit(*c)) c++;
+      dev_number = (int)strtol(c, NULL, 10);
+      *c = '\0';
+      len = WI_MAXSTRLEN;
+   }
+
    snprintf(mib, sizeof(mib), "dev.%s.%d.%%desc", dev_name, dev_number);
    if(sysctlbyname(mib, buffer, &len, NULL, 0) == -1)
       return (WI_NOSUCHDEV);
-#else
-#define WI_RID_STA_IDENTITY_LUCENT	0x1
-#define WI_RID_STA_IDENTITY_PRISMII	0x2
-#define WI_RID_STA_IDENTITY_SAMSUNG	0x3
-#define WI_RID_STA_IDENTITY_DLINK	0x6
-  const char* vendor = "Unknown";
-  struct wi_req wr;
-  int result;
-
-  bzero((void*)&wr, sizeof(wr));
-  wr.wi_len = WI_MAX_DATALEN;
-  wr.wi_type = WI_RID_STA_IDENTITY;
-
-  if ((result = _wi_getval(device, &wr)) != WI_OK){
-    /* For the Atheros, IDENTITY does not work. */
-    if (strcmp(device->interface, "ath") != 0)
-      return(result);
-  }
-  else if (wr.wi_len < 4)
-    return(WI_NOSUCHDEV);
-
-  switch (wr.wi_val[1]) {
-  case WI_RID_STA_IDENTITY_LUCENT:
-    vendor = "Lucent";
-    break;
-
-  case WI_RID_STA_IDENTITY_PRISMII:
-    vendor = "generic PRISM II";
-    break;
-
-  case WI_RID_STA_IDENTITY_SAMSUNG:
-		vendor = "Samsung";
-		break;
-	case WI_RID_STA_IDENTITY_DLINK:
-		vendor = "D-Link";
-		break;
-  }
-
-  snprintf(buffer, len, "%s (ID %d, version %d.%d)", vendor,
-      wr.wi_val[0], wr.wi_val[2], wr.wi_val[3]);
-#endif
 
   return(WI_OK);
 }
-#endif /* wi_vendor */
 
-/* NetBSD and FreeBSD 6.x uses old wi_* API */
-#if defined(__NetBSD__) || defined(__FreeBSD_kernel__)
-/* FreeBSD 7.x use its own new iee80211 API */
-#if defined(__FreeBSD_kernel__) && __FreeBSD_kernel_version >= 700000
 static int
 _wi_getval(const struct wi_device *device, struct ieee80211req_scan_result *scan)
 {
@@ -393,7 +349,9 @@
 
    return(WI_OK);
 }
-#else
+#endif
+
+#if defined(__NetBSD__)
 static int
 _wi_getval(const struct wi_device *device, struct wi_req *wr)
 {
@@ -409,10 +367,11 @@
   return(WI_OK);
 }
 #endif
+
 static int
 _wi_netname(const struct wi_device *device, char *buffer, size_t len)
 {
-#if defined(__FreeBSD_kernel__) && __FreeBSD_kernel_version >= 700000
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
    struct ieee80211req ireq;
 
    memset(&ireq, 0, sizeof(ireq));
@@ -423,7 +382,7 @@
    ireq.i_len = len; 
    if (ioctl(device->socket, SIOCG80211, &ireq) < 0) 
       return WI_NOSUCHDEV;
-#else
+#elif defined(__NetBSD__)
   struct wi_req wr;
   int result;
 
@@ -443,7 +402,7 @@
 static int
 _wi_quality(const struct wi_device *device, int *quality)
 {
-#if defined(__FreeBSD_kernel__) && __FreeBSD_kernel_version >= 700000
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
    struct ieee80211req_scan_result req;
    int result;
    bzero(&req, sizeof(req));
@@ -451,8 +410,16 @@
    if((result = _wi_getval(device, &req)) != WI_OK)
       return (result);
 
-   *quality = req.isr_rssi;
-#else
+   /*
+    * FreeBSD's wlan stats:
+    *	signal (in dBm) = rssi * 2 + noise;
+    *	quality_bars    = 4 * (signal - noise);
+    * or
+    *	quality_bars    = rssi * 8;
+    * but, per wi_query(), above, we need to return strength in dBm, so... 
+    */
+   *quality = req.isr_rssi * 2 + req.isr_noise;
+#elif defined(__NetBSD__)
   struct wi_req wr;
   int result;
 
@@ -475,7 +442,7 @@
 static int
 _wi_rate(const struct wi_device *device, int *rate)
 {
-#if defined(__FreeBSD_kernel__) && __FreeBSD_kernel_version >= 700000
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
    struct ieee80211req_scan_result req;
    int result, i, high;
    bzero(&req, sizeof(req));
@@ -488,7 +455,7 @@
          high = req.isr_rates[i] & IEEE80211_RATE_VAL;
    
    *rate = high / 2;
-#else
+#elif defined(__NetBSD__)
   struct wi_req wr;
   int result;
 
@@ -505,5 +472,4 @@
   return(WI_OK);
 }
 
-#endif  /* defined(__NetBSD__) || defined(__FreeBSD_kernel__) */
 #endif
