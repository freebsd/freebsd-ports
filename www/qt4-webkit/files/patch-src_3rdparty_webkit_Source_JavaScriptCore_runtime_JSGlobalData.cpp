--- src/3rdparty/webkit/Source/JavaScriptCore/runtime/JSGlobalData.cpp.orig	2017-07-01 07:49:26 UTC
+++ src/3rdparty/webkit/Source/JavaScriptCore/runtime/JSGlobalData.cpp
@@ -121,7 +121,11 @@ void JSGlobalData::storeVPtrs()
 {
     // Enough storage to fit a JSArray, JSByteArray, JSString, or JSFunction.
     // COMPILE_ASSERTS below check that this is true.
+#if defined(__aarch64__)
+    char storage[128];
+#else
     char storage[64];
+#endif
 
     COMPILE_ASSERT(sizeof(JSArray) <= sizeof(storage), sizeof_JSArray_must_be_less_than_storage);
     JSCell* jsArray = new (storage) JSArray(JSArray::VPtrStealingHack);
