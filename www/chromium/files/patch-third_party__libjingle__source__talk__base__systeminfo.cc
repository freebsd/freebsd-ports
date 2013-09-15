--- third_party/libjingle/source/talk/base/systeminfo.cc.orig	2013-09-03 03:20:59.000000000 -0400
+++ third_party/libjingle/source/talk/base/systeminfo.cc	2013-09-12 15:47:30.000000000 -0400
@@ -36,7 +36,7 @@
 #elif defined(OSX)
 #include <ApplicationServices/ApplicationServices.h>
 #include <CoreServices/CoreServices.h>
-#elif defined(LINUX) || defined(ANDROID)
+#elif defined(LINUX) || defined(ANDROID) || defined(BSD)
 #include <unistd.h>
 #endif
 #if defined(OSX) || defined(IOS)
@@ -48,7 +48,7 @@
 #include "talk/base/win32.h"
 #elif defined(OSX)
 #include "talk/base/macconversion.h"
-#elif defined(LINUX) || defined(ANDROID)
+#elif defined(LINUX) || defined(ANDROID) || defined(BSD)
 #include "talk/base/linux.h"
 #endif
 #include "talk/base/common.h"
