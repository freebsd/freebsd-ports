--- xbmc/addons/Addon.cpp.orig
+++ xbmc/addons/Addon.cpp
@@ -28,6 +28,9 @@
 #ifdef __APPLE__
 #include "../osx/OSXGNUReplacements.h"
 #endif
+#ifdef __FreeBSD__
+#include "FreeBSDGNUReplacements.h" // strverscmp
+#endif
 #include "utils/log.h"
 #include "utils/URIUtils.h"
 #include <vector>
