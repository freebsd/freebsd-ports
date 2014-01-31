--- ./panel-plugin/wi_bsd.c.orig	2012-04-09 16:45:20.000000000 +0000
+++ ./panel-plugin/wi_bsd.c	2014-01-31 09:31:51.000000000 +0000
@@ -52,10 +52,6 @@
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <net80211/ieee80211_ioctl.h>
-#else
-#include <net/if_var.h>
-#include <net/ethernet.h>
-#include <dev/wi/if_wavelan_ieee.h>
 #endif
 #else
 #ifdef __NetBSD__
@@ -111,8 +107,6 @@
 static int _wi_vendor(const struct wi_device *, char *, size_t);
 #if __FreeBSD_kernel_version > 700000
 static int _wi_getval(const struct wi_device *, struct ieee80211req_scan_result *);
-#else
-static int _wi_getval(const struct wi_device *, struct wi_req *);
 #endif
 #endif
 static int _wi_netname(const struct wi_device *, char *, size_t);
@@ -319,46 +313,6 @@
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
 #endif
 
   return(WI_OK);
@@ -393,21 +347,6 @@
 
    return(WI_OK);
 }
-#else
-static int
-_wi_getval(const struct wi_device *device, struct wi_req *wr)
-{
-  struct ifreq ifr;
-
-  bzero((void*)&ifr, sizeof(ifr));
-  strlcpy(ifr.ifr_name, device->interface, sizeof(ifr.ifr_name));
-  ifr.ifr_data = (void*)wr;
-
-  if (ioctl(device->socket, SIOCGWAVELAN, &ifr) < 0)
-    return(WI_NOSUCHDEV);
-
-  return(WI_OK);
-}
 #endif
 static int
 _wi_netname(const struct wi_device *device, char *buffer, size_t len)
@@ -423,18 +362,6 @@
    ireq.i_len = len; 
    if (ioctl(device->socket, SIOCG80211, &ireq) < 0) 
       return WI_NOSUCHDEV;
-#else
-  struct wi_req wr;
-  int result;
-
-  bzero((void *)&wr, sizeof(wr));
-  wr.wi_len = WI_MAX_DATALEN;
-  wr.wi_type = WI_RID_CURRENT_SSID;
-
-  if ((result = _wi_getval(device, &wr)) != WI_OK)
-    return(result);
-
-  strlcpy(buffer, (char *)&wr.wi_val[1], MIN(len, le16toh(wr.wi_val[0]) + 1));
 #endif
 
   return(WI_OK);
@@ -452,21 +379,6 @@
       return (result);
 
    *quality = req.isr_rssi;
-#else
-  struct wi_req wr;
-  int result;
-
-  bzero((void *)&wr, sizeof(wr));
-  wr.wi_len = WI_MAX_DATALEN;
-  wr.wi_type = WI_RID_COMMS_QUALITY;
-
-  if ((result = _wi_getval(device, &wr)) != WI_OK)
-    return(result);
-
-  /* according to various implementation (conky, ifconfig) :
-     wi_val[0] = quality, wi_val[1] = signal, wi_val[2] = noise
-     but my ral only shows a value for signal, and it seems it's a dB value */
-  *quality = le16toh(wr.wi_val[1]);
 #endif
 
   return(WI_OK);
@@ -488,18 +400,6 @@
          high = req.isr_rates[i] & IEEE80211_RATE_VAL;
    
    *rate = high / 2;
-#else
-  struct wi_req wr;
-  int result;
-
-  bzero((void *)&wr, sizeof(wr));
-  wr.wi_len = WI_MAX_DATALEN;
-  wr.wi_type = WI_RID_CUR_TX_RATE;
-
-  if ((result = _wi_getval(device, &wr)) != WI_OK)
-    return(result);
-
-  *rate = le16toh(wr.wi_val[0]);
 #endif
 
   return(WI_OK);
