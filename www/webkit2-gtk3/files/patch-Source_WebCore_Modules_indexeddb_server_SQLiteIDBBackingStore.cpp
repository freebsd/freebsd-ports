.build/lib/libwebkit2gtk-4.0.so: undefined reference to `JSC::JSObject::didBecomePrototype()'

https://trac.webkit.org/changeset/246922/webkit

--- Source/WebCore/Modules/indexeddb/server/SQLiteIDBBackingStore.cpp.orig	2019-08-26 14:55:44 UTC
+++ Source/WebCore/Modules/indexeddb/server/SQLiteIDBBackingStore.cpp
@@ -48,11 +48,8 @@
 #include "SQLiteTransaction.h"
 #include "ThreadSafeDataBuffer.h"
 #include <JavaScriptCore/AuxiliaryBarrierInlines.h>
-#include <JavaScriptCore/HeapInlines.h>
-#include <JavaScriptCore/JSCJSValueInlines.h>
-#include <JavaScriptCore/JSGlobalObject.h>
+#include <JavaScriptCore/JSCInlines.h>
 #include <JavaScriptCore/StrongInlines.h>
-#include <JavaScriptCore/StructureInlines.h>
 #include <wtf/FileSystem.h>
 #include <wtf/NeverDestroyed.h>
 #include <wtf/text/StringConcatenateNumbers.h>
