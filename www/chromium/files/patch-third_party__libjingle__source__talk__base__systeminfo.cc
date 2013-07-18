--- third_party/libjingle/source/talk/base/systeminfo.cc.orig	2013-07-15 17:40:34.000000000 +0300
+++ third_party/libjingle/source/talk/base/systeminfo.cc	2013-07-15 17:41:14.000000000 +0300
@@ -48,7 +48,7 @@
 #include "talk/base/win32.h"
 #elif defined(OSX)
 #include "talk/base/macconversion.h"
-#elif defined(LINUX) || defined(ANDROID)
+#elif defined(LINUX) || defined(ANDROID) || defined(BSD)
 #include "talk/base/linux.h"
 #endif
 #include "talk/base/common.h"
