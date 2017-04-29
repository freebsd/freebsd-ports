--- third_party/WebKit/Source/wtf/StackUtil.cpp.orig	2017-04-19 19:06:50 UTC
+++ third_party/WebKit/Source/wtf/StackUtil.cpp
@@ -8,6 +8,10 @@
 #include "wtf/Threading.h"
 #include "wtf/WTFThreadData.h"
 
+#if OS(FREEBSD)
+#include <pthread_np.h>
+#endif
+
 #if OS(WIN)
 #include <stddef.h>
 #include <windows.h>
