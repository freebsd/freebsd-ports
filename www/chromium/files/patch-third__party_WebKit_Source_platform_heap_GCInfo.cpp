--- third_party/WebKit/Source/platform/heap/GCInfo.cpp.orig	2016-04-08 16:02:13 UTC
+++ third_party/WebKit/Source/platform/heap/GCInfo.cpp
@@ -7,6 +7,8 @@
 #include "platform/heap/Handle.h"
 #include "platform/heap/Heap.h"
 
+#include <stdlib.h>
+
 namespace blink {
 
 // GCInfo indices start from 1 for heap objects, with 0 being treated
