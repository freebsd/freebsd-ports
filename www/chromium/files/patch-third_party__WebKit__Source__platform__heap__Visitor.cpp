--- third_party/WebKit/Source/platform/heap/Visitor.cpp.orig	2015-04-19 21:39:50.000000000 +0200
+++ third_party/WebKit/Source/platform/heap/Visitor.cpp	2015-04-19 21:40:31.000000000 +0200
@@ -34,6 +34,8 @@
 #include "platform/heap/Handle.h"
 #include "platform/heap/Heap.h"
 
+#include <stdlib.h>
+
 namespace blink {
 
 // GCInfo indices start from 1 for heap objects, with 0 being treated
