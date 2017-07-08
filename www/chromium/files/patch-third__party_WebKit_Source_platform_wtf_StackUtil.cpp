--- third_party/WebKit/Source/platform/wtf/StackUtil.cpp.orig	2017-06-05 19:03:26 UTC
+++ third_party/WebKit/Source/platform/wtf/StackUtil.cpp
@@ -8,6 +8,10 @@
 #include "platform/wtf/Threading.h"
 #include "platform/wtf/WTFThreadData.h"
 
+#if OS(FREEBSD)
+#include <pthread_np.h>
+#endif
+
 #if OS(WIN)
 #include <stddef.h>
 #include <windows.h>
