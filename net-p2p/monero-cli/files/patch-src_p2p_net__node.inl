--- src/p2p/net_node.inl.orig	2023-10-02 19:28:11 UTC
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
@@ -2989,7 +2989,11 @@ namespace nodetool
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
@@ -3057,10 +3061,18 @@ namespace nodetool
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
 
@@ -3071,10 +3083,17 @@ namespace nodetool
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
