--- third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp.orig	2017-06-05 19:03:26 UTC
+++ third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp
@@ -7,6 +7,8 @@
 #include "platform/wtf/StackUtil.h"
 #include "public/platform/Platform.h"
 
+#include <pthread_np.h>
+
 #if OS(WIN)
 #include <stddef.h>
 #include <windows.h>
