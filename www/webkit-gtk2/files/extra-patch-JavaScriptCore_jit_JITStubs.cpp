--- JavaScriptCore/jit/JITStubs.cpp.orig	2009-10-19 15:13:27.000000000 -0400
+++ JavaScriptCore/jit/JITStubs.cpp	2009-10-19 15:13:46.000000000 -0400
@@ -2672,7 +2672,7 @@ DEFINE_STUB_FUNCTION(EncodedJSValue, op_
 
     if (!handler) {
         *stackFrame.exception = exceptionValue;
-        STUB_SET_RETURN_ADDRESS(reinterpret_cast<void*>(ctiOpThrowNotCaught));
+        STUB_SET_RETURN_ADDRESS((void*)(ctiOpThrowNotCaught));
         return JSValue::encode(jsNull());
     }
 
