--- src/3rdparty/chromium/third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp
@@ -6,6 +6,8 @@
 
 #include "public/platform/Platform.h"
 
+#include <pthread_np.h>
+
 #if OS(WIN)
 #include <stddef.h>
 #include <windows.h>
