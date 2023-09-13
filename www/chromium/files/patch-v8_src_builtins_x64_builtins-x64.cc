--- v8/src/builtins/x64/builtins-x64.cc.orig	2023-09-13 12:11:42 UTC
+++ v8/src/builtins/x64/builtins-x64.cc
@@ -44,6 +44,8 @@ namespace internal {
 #define __ ACCESS_MASM(masm)
 
 void Builtins::Generate_Adaptor(MacroAssembler* masm, Address address) {
+  __ CodeEntry();
+
   __ LoadAddress(kJavaScriptCallExtraArg1Register,
                  ExternalReference::Create(address));
   __ Jump(BUILTIN_CODE(masm->isolate(), AdaptorWithBuiltinExitFrame),
@@ -430,7 +432,7 @@ void Generate_JSEntryVariant(MacroAssembler* masm, Sta
   // Jump to a faked try block that does the invoke, with a faked catch
   // block that sets the pending exception.
   __ jmp(&invoke);
-  __ bind(&handler_entry);
+  __ BindExceptionHandler(&handler_entry);
 
   // Store the current pc as the handler offset. It's used later to create the
   // handler table.
@@ -4015,6 +4017,8 @@ void GenericJSToWasmWrapperHelper(MacroAssembler* masm
     RestoreParentSuspender(masm, rbx, rcx);
   }
   __ bind(&suspend);
+
+  __ endbr64();
   // No need to process the return value if the stack is suspended, there is a
   // single 'externref' value (the promise) which doesn't require conversion.
 
@@ -4281,6 +4285,9 @@ void GenericJSToWasmWrapperHelper(MacroAssembler* masm
   // thrown exception.
   if (stack_switch) {
     int catch_handler = __ pc_offset();
+
+    __ endbr64();
+
     // Restore rsp to free the reserved stack slots for the sections.
     __ leaq(rsp, MemOperand(rbp, kLastSpillOffset));
 
@@ -4567,6 +4574,7 @@ void Builtins::Generate_WasmSuspend(MacroAssembler* ma
   LoadJumpBuffer(masm, jmpbuf, true);
   __ Trap();
   __ bind(&resume);
+  __ endbr64();
   __ LeaveFrame(StackFrame::STACK_SWITCH);
   __ ret(0);
 }
@@ -4711,6 +4719,7 @@ void Generate_WasmResumeHelper(MacroAssembler* masm, w
   }
   __ Trap();
   __ bind(&suspend);
+  __ endbr64();
   __ LeaveFrame(StackFrame::STACK_SWITCH);
   // Pop receiver + parameter.
   __ ret(2 * kSystemPointerSize);
