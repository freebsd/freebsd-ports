--- clientgui/AsyncRPC.cpp.orig		2012-04-07 11:55:37.000000000 +0300
+++ clientgui/AsyncRPC.cpp		2012-04-07 11:56:14.000000000 +0300
@@ -20,7 +20,9 @@
 #endif
 
 #if !(defined(_WIN32) || (defined(__WXMAC__) && (MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_10_4)))
+#if !defined(NO_PER_THREAD_LOCALE)
 #include <xlocale.h>
+#endif
 //#include "gui_rpc_client.h"
 #endif
 
