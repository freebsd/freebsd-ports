--- src/3rdparty/chromium/third_party/WebKit/Source/platform/heap/GCInfo.cpp.orig	2017-01-26 00:49:28 UTC
+++ src/3rdparty/chromium/third_party/WebKit/Source/platform/heap/GCInfo.cpp
@@ -7,6 +7,8 @@
 #include "platform/heap/Handle.h"
 #include "platform/heap/Heap.h"
 
+#include <stdlib.h>
+
 namespace blink {
 
 // GCInfo indices start from 1 for heap objects, with 0 being treated
