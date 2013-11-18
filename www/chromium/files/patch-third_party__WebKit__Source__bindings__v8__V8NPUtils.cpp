--- third_party/WebKit/Source/bindings/v8/V8NPUtils.cpp.orig	2013-11-08 07:50:07.000000000 +0100
+++ third_party/WebKit/Source/bindings/v8/V8NPUtils.cpp	2013-11-15 16:15:06.000000000 +0100
@@ -39,6 +39,8 @@
 #include "core/page/DOMWindow.h"
 #include "wtf/text/WTFString.h"
 
+#include <stdlib.h>
+
 namespace WebCore {
 
 void convertV8ObjectToNPVariant(v8::Local<v8::Value> object, NPObject* owner, NPVariant* result, v8::Isolate* isolate)
