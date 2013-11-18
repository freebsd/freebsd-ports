--- third_party/WebKit/Source/bindings/v8/V8PerContextData.cpp.orig	2013-11-08 07:50:07.000000000 +0100
+++ third_party/WebKit/Source/bindings/v8/V8PerContextData.cpp	2013-11-15 16:16:51.000000000 +0100
@@ -35,6 +35,8 @@
 #include "bindings/v8/V8ObjectConstructor.h"
 #include "wtf/StringExtras.h"
 
+#include <stdlib.h>
+
 namespace WebCore {
 
 template<typename Map>
