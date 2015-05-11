--- third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp.orig	2015-04-19 21:53:42.000000000 +0200
+++ third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp	2015-04-19 21:54:12.000000000 +0200
@@ -7,6 +7,8 @@
 
 #include "public/platform/Platform.h"
 
+#include <pthread_np.h>
+
 #if OS(WIN)
 #include <stddef.h>
 #include <windows.h>
