--- libretroshare/src/upnp/upnphandler.h~	2010-07-04 12:42:17.000000000 +0200
+++ libretroshare/src/upnp/upnphandler.h	2012-01-15 05:26:45.000000000 +0100
@@ -13,7 +13,11 @@
 #include "util/rsthreads.h"
 
 #include <upnp/upnp.h>
+#ifdef do_not_use_this
+#include "upnp/UPnPBase.cpp"
+#else
 #include "upnp/UPnPBase.h"
+#endif
 
 #define RS_UPNP_S_UNINITIALISED  0
 #define RS_UPNP_S_UNAVAILABLE    1
