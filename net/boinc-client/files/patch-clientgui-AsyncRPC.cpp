--- clientgui/AsyncRPC.cpp.orig		2012-04-07 11:55:37.000000000 +0300
+++ clientgui/AsyncRPC.cpp		2012-04-07 11:56:14.000000000 +0300
@@ -20,7 +20,12 @@
 #endif
 
 #if !(defined(_WIN32) || (defined(__WXMAC__) && (MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_10_4)))
-#include <xlocale.h>
+#ifdef __FreeBSD__
+# include <osreldate.h>
+# if __FreeBSD_version >= 1000002
+#  include <xlocale.h>
+# endif
+#endif
 //#include "gui_rpc_client.h"
 #endif
 
