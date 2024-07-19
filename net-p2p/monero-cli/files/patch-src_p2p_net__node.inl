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
@@ -3057,7 +3061,11 @@ namespace nodetool
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
