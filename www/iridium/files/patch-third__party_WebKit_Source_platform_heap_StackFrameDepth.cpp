--- third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp.orig	2017-04-19 19:06:50 UTC
+++ third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp
@@ -7,6 +7,8 @@
 #include "public/platform/Platform.h"
 #include "wtf/StackUtil.h"
 
+#include <pthread_np.h>
+
 #if OS(WIN)
 #include <stddef.h>
 #include <windows.h>
