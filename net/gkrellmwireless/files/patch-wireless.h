--- wireless.h.orig	2001-09-09 16:25:55.000000000 +0200
+++ wireless.h	2008-03-18 12:07:33.000000000 +0100
@@ -21,9 +21,14 @@
 #include <gkrellm/gkrellm.h>
 #ifdef __FreeBSD__
   #include <net/if.h>
-  #include <machine/if_wavelan_ieee.h>
+  #include <dev/wi/if_wavelan_ieee.h>
   #define ANCACHE
   #include <dev/an/if_aironet_ieee.h>
+  #if __FreeBSD_version > 600034
+    #include <ifaddrs.h>
+    #include <net/if_media.h>
+    #include <net80211/ieee80211_ioctl.h>
+  #endif
 #endif
 
 #ifdef __NetBSD__
