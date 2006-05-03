--- src/backend.c.orig	Wed May  3 02:41:00 2006
+++ src/backend.c	Wed May  3 03:03:09 2006
@@ -20,6 +20,7 @@
 #include <config.h>
 #include <glibtop/netlist.h>
 #include <glibtop/netload.h>
+#include <net/if_media.h>
 #include "backend.h"
 
 /* Check for all available devices. This really should be
@@ -131,7 +132,7 @@
 
 	g_strlcpy(request.ifr_name, devinfo->name, sizeof request.ifr_name);
 
-	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
+	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
 		goto out;
 
 	if (ioctl(fd, SIOCGIFFLAGS, &request) == -1)
@@ -148,16 +149,20 @@
 		}
 	}
 
+	if (devinfo->type == DEV_UNKNOWN) {
+		struct ifmediareq ifmr;  
 
-	if (ioctl(fd, SIOCGIWNAME, &request) >= 0) {
-		devinfo->type = DEV_WIRELESS;
-	}
+		memset(&ifmr, 0, sizeof(ifmr));
+		g_strlcpy(ifmr.ifm_name, devinfo->name, sizeof(ifmr.ifm_name));
 
-	if (ioctl(fd, SIOCGIWENCODE, &request) >= 0) {
-		g_assert_not_reached();
+		if (ioctl(fd, SIOCGIFMEDIA, &ifmr) >= 0) {
+			switch (IFM_TYPE(ifmr.ifm_current)) {
+			case IFM_ETHER:		devinfo->type = DEV_ETHERNET; break;
+			case IFM_IEEE80211:	devinfo->type = DEV_WIRELESS; break;
+			}
+		}
 	}
     
-    
  out:
 	if(fd != -1)
 		close(fd);
@@ -210,9 +215,6 @@
 		else {
 			devinfo.type = DEV_PPP;
 		}
-	}
-	else if (g_str_has_prefix(device, "eth")) {
-		devinfo.type = DEV_ETHERNET;
 	}
 
 	get_additional_info(&devinfo);
