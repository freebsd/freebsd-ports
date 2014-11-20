--- device/hid/hid_service.cc.orig	2014-10-14 17:38:39 UTC
+++ device/hid/hid_service.cc
@@ -15,7 +15,7 @@
 #include "device/hid/hid_service_linux.h"
 #elif defined(OS_MACOSX)
 #include "device/hid/hid_service_mac.h"
-#else
+#elif !defined(OS_BSD)
 #include "device/hid/hid_service_win.h"
 #endif
 
