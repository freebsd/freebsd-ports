--- JavaScriptCore/jit/JITStubCall.h.orig	2009-10-18 13:44:09.000000000 -0400
+++ JavaScriptCore/jit/JITStubCall.h	2009-10-18 13:45:53.000000000 -0400
@@ -36,7 +36,7 @@ namespace JSC {
     public:
         JITStubCall(JIT* jit, JSObject* (JIT_STUB *stub)(STUB_ARGS_DECLARATION))
             : m_jit(jit)
-            , m_stub(reinterpret_cast<void*>(stub))
+            , m_stub((void*)(stub))
             , m_returnType(Cell)
             , m_stackIndex(stackIndexStart)
         {
@@ -44,7 +44,7 @@ namespace JSC {
 
         JITStubCall(JIT* jit, JSPropertyNameIterator* (JIT_STUB *stub)(STUB_ARGS_DECLARATION))
             : m_jit(jit)
-            , m_stub(reinterpret_cast<void*>(stub))
+            , m_stub((void*)(stub))
             , m_returnType(Cell)
             , m_stackIndex(stackIndexStart)
         {
@@ -52,7 +52,7 @@ namespace JSC {
 
         JITStubCall(JIT* jit, void* (JIT_STUB *stub)(STUB_ARGS_DECLARATION))
             : m_jit(jit)
-            , m_stub(reinterpret_cast<void*>(stub))
+            , m_stub((void*)(stub))
             , m_returnType(VoidPtr)
             , m_stackIndex(stackIndexStart)
         {
@@ -60,7 +60,7 @@ namespace JSC {
 
         JITStubCall(JIT* jit, int (JIT_STUB *stub)(STUB_ARGS_DECLARATION))
             : m_jit(jit)
-            , m_stub(reinterpret_cast<void*>(stub))
+            , m_stub((void*)(stub))
             , m_returnType(Int)
             , m_stackIndex(stackIndexStart)
         {
@@ -68,7 +68,7 @@ namespace JSC {
 
         JITStubCall(JIT* jit, bool (JIT_STUB *stub)(STUB_ARGS_DECLARATION))
             : m_jit(jit)
-            , m_stub(reinterpret_cast<void*>(stub))
+            , m_stub((void*)(stub))
             , m_returnType(Int)
             , m_stackIndex(stackIndexStart)
         {
@@ -76,7 +76,7 @@ namespace JSC {
 
         JITStubCall(JIT* jit, void (JIT_STUB *stub)(STUB_ARGS_DECLARATION))
             : m_jit(jit)
-            , m_stub(reinterpret_cast<void*>(stub))
+            , m_stub((void*)(stub))
             , m_returnType(Void)
             , m_stackIndex(stackIndexStart)
         {
@@ -85,7 +85,7 @@ namespace JSC {
 #if USE(JSVALUE32_64)
         JITStubCall(JIT* jit, EncodedJSValue (JIT_STUB *stub)(STUB_ARGS_DECLARATION))
             : m_jit(jit)
-            , m_stub(reinterpret_cast<void*>(stub))
+            , m_stub((void*)(stub))
             , m_returnType(Value)
             , m_stackIndex(stackIndexStart)
         {
