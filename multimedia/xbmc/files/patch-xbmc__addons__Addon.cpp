--- ./xbmc/addons/Addon.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/addons/Addon.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -28,6 +28,9 @@
 #ifdef __APPLE__
 #include "../osx/OSXGNUReplacements.h"
 #endif
+#ifdef __FreeBSD__
+#include "FreeBSDGNUReplacements.h"
+#endif
 #include "utils/log.h"
 #include "utils/URIUtils.h"
 #include <vector>
