--- xbmc/storage/linux/DeviceKitDisksProvider.cpp.orig	2015-04-13 10:45:50 UTC
+++ xbmc/storage/linux/DeviceKitDisksProvider.cpp
@@ -19,6 +19,7 @@
  */
 #include "DeviceKitDisksProvider.h"
 #ifdef HAS_DBUS
+#include <stdlib.h>
 #include "settings/AdvancedSettings.h"
 #include "guilib/LocalizeStrings.h"
 #include "utils/log.h"
