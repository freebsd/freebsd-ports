--- third_party/WebKit/Source/wtf/StackUtil.cpp.orig	2017-03-09 20:04:46 UTC
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
