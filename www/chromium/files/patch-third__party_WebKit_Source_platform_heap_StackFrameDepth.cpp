--- third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp.orig	2016-05-11 19:02:33 UTC
+++ third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp
@@ -6,6 +6,8 @@
 
 #include "public/platform/Platform.h"
 
+#include <pthread_np.h>
+
 #if OS(WIN)
 #include <stddef.h>
 #include <windows.h>
