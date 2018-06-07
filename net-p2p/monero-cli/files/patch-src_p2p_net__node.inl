--- src/p2p/net_node.inl.orig	2018-06-06 19:28:51.925128000 UTC
+++ src/p2p/net_node.inl	2018-06-06 19:29:06.877331000 UTC
@@ -49,9 +49,9 @@
 #include "storages/levin_abstract_invoke2.h"
 #include "cryptonote_core/cryptonote_core.h"
 
-#include <miniupnp/miniupnpc/miniupnpc.h>
-#include <miniupnp/miniupnpc/upnpcommands.h>
-#include <miniupnp/miniupnpc/upnperrors.h>
+#include <miniupnpc/miniupnpc.h>
+#include <miniupnpc/upnpcommands.h>
+#include <miniupnpc/upnperrors.h>
 
 #undef MONERO_DEFAULT_LOG_CATEGORY
 #define MONERO_DEFAULT_LOG_CATEGORY "net.p2p"
