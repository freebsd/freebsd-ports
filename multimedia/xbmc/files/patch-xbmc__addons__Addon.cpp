Index: xbmc/addons/Addon.cpp
===================================================================
--- xbmc/addons/Addon.cpp	(revision 35575)
+++ xbmc/addons/Addon.cpp	(working copy)
@@ -29,6 +29,9 @@
 #ifdef __APPLE__
 #include "../osx/OSXGNUReplacements.h"
 #endif
+#ifdef __FreeBSD__
+#include "FreeBSDGNUReplacements.h" // strverscmp
+#endif
 #include "log.h"
 #include <vector>
 #include <string.h>
