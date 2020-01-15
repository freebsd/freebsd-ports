--- lib/LLVMIRCodeGen/LLVMCompiledFunction.cpp.orig	2020-01-15 20:31:37 UTC
+++ lib/LLVMIRCodeGen/LLVMCompiledFunction.cpp
@@ -99,7 +99,7 @@ Error LLVMCompiledFunction::execute(ExecutionContext *
   auto *traceContext = context->getTraceContext();
   TRACE_EVENT_SCOPE_NAMED(traceContext, TraceLevel::RUNTIME,
                           "findJitmainSymbol", fjEvent);
-  Expected<llvm::JITTargetAddress> address = NULL;
+  Expected<llvm::JITTargetAddress> address = 0;
   {
     std::lock_guard<std::mutex> lock(JITLock_);
     auto sym = JIT_->findSymbol("jitmain");
