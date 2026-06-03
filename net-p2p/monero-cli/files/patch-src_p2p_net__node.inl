--- src/p2p/net_node.inl.orig	2025-10-07 19:25:41 UTC
+++ src/p2p/net_node.inl
@@ -60,9 +60,9 @@
 #include "cryptonote_core/cryptonote_core.h"
 #include "net/parse.h"
 
-#include <miniupnp/miniupnpc/miniupnpc.h>
-#include <miniupnp/miniupnpc/upnpcommands.h>
-#include <miniupnp/miniupnpc/upnperrors.h>
+#include <miniupnpc/miniupnpc.h>
+#include <miniupnpc/upnpcommands.h>
+#include <miniupnpc/upnperrors.h>
 
 #undef MONERO_DEFAULT_LOG_CATEGORY
 #define MONERO_DEFAULT_LOG_CATEGORY "net.p2p"
@@ -3090,7 +3090,11 @@ namespace nodetool
     UPNPUrls urls;
     IGDdatas igdData;
     char lanAddress[64];
+#if MINIUPNPC_API_VERSION >= 18
+    result = UPNP_GetValidIGD(deviceList, &urls, &igdData, lanAddress, sizeof lanAddress, NULL, 0);
+#else
     result = UPNP_GetValidIGD(deviceList, &urls, &igdData, lanAddress, sizeof lanAddress);
+#endif 
     freeUPNPDevlist(deviceList);
     if (result > 0) {
       if (result == 1) {
@@ -3158,10 +3162,18 @@ namespace nodetool
     UPNPUrls urls;
     IGDdatas igdData;
     char lanAddress[64];
+#if MINIUPNPC_API_VERSION >= 18
+    result = UPNP_GetValidIGD(deviceList, &urls, &igdData, lanAddress, sizeof lanAddress, NULL, 0);
+#else
     result = UPNP_GetValidIGD(deviceList, &urls, &igdData, lanAddress, sizeof lanAddress);
+#endif 
     freeUPNPDevlist(deviceList);
     if (result > 0) {
+#if MINIUPNPC_API_VERSION >= 18
+      if ((result == 1) || (result == 2)) {
+#else
       if (result == 1) {
+#endif 
         std::ostringstream portString;
         portString << port;
 
@@ -3172,10 +3184,17 @@ namespace nodetool
         } else {
           MLOG_GREEN(el::Level::Info, "Deleted IGD port mapping.");
         }
+#if MINIUPNPC_API_VERSION >= 18
+      } else if (result == 3) {
+        MWARNING("IGD was found but reported as not connected.");
+      } else if (result == 4) {
+        MWARNING("UPnP device was found but not recognized as IGD.");
+#else
       } else if (result == 2) {
         MWARNING("IGD was found but reported as not connected.");
       } else if (result == 3) {
         MWARNING("UPnP device was found but not recognized as IGD.");
+#endif 
       } else {
         MWARNING("UPNP_GetValidIGD returned an unknown result code.");
       }
