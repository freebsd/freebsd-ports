--- third_party/WebKit/Source/bindings/v8/npruntime.cpp.orig	2013-11-08 07:50:07.000000000 +0100
+++ third_party/WebKit/Source/bindings/v8/npruntime.cpp	2013-11-15 16:19:52.000000000 +0100
@@ -36,6 +36,8 @@
 #include "wtf/HashSet.h"
 #include "wtf/HashTableDeletedValueType.h"
 
+#include <stdlib.h>
+
 using namespace WebCore;
 
 // FIXME: Consider removing locks if we're singlethreaded already.
