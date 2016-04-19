--- xbmc/storage/linux/UDisksProvider.cpp.orig	2016-02-20 15:21:19 UTC
+++ xbmc/storage/linux/UDisksProvider.cpp
@@ -19,6 +19,7 @@
  */
 #include "UDisksProvider.h"
 #ifdef HAS_DBUS
+#include <stdlib.h>
 #include "settings/AdvancedSettings.h"
 #include "guilib/LocalizeStrings.h"
 #include "utils/log.h"
