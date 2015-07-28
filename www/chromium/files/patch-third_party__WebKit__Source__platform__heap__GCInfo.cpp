--- third_party/WebKit/Source/platform/heap/GCInfo.cpp.orig	2015-07-22 08:00:24.013307000 -0400
+++ third_party/WebKit/Source/platform/heap/GCInfo.cpp	2015-07-22 08:00:35.112590000 -0400
@@ -8,6 +8,8 @@
 #include "platform/heap/Handle.h"
 #include "platform/heap/Heap.h"
 
+#include <stdlib.h>
+
 namespace blink {
 
 // GCInfo indices start from 1 for heap objects, with 0 being treated
