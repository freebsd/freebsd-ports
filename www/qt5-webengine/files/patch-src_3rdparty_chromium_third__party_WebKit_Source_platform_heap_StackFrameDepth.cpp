--- src/3rdparty/chromium/third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp.orig	2017-01-26 00:49:28 UTC
+++ src/3rdparty/chromium/third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp
@@ -6,6 +6,8 @@
 
 #include "public/platform/Platform.h"
 
+#include <pthread_np.h>
+
 #if OS(WIN)
 #include <stddef.h>
 #include <windows.h>
