--- v8/src/builtins/x64/builtins-x64.cc.orig	2023-07-16 15:47:57 UTC
+++ v8/src/builtins/x64/builtins-x64.cc
@@ -43,6 +43,8 @@ namespace internal {
 #define __ ACCESS_MASM(masm)
 
 void Builtins::Generate_Adaptor(MacroAssembler* masm, Address address) {
+  __ CodeEntry();
+
   __ LoadAddress(kJavaScriptCallExtraArg1Register,
                  ExternalReference::Create(address));
   __ Jump(BUILTIN_CODE(masm->isolate(), AdaptorWithBuiltinExitFrame),
@@ -457,7 +459,7 @@ void Generate_JSEntryVariant(MacroAssembler* masm, Sta
   // Jump to a faked try block that does the invoke, with a faked catch
   // block that sets the pending exception.
   __ jmp(&invoke);
-  __ bind(&handler_entry);
+  __ BindExceptionHandler(&handler_entry);
 
   // Store the current pc as the handler offset. It's used later to create the
   // handler table.
@@ -3801,6 +3803,8 @@ void GenericJSToWasmWrapperHelper(MacroAssembler* masm
     RestoreParentSuspender(masm, rbx, rcx);
   }
   __ bind(&suspend);
+
+  __ endbr64();
   // No need to process the return value if the stack is suspended, there is a
   // single 'externref' value (the promise) which doesn't require conversion.
 
@@ -4165,6 +4169,7 @@ void Builtins::Generate_WasmSuspend(MacroAssembler* ma
   LoadJumpBuffer(masm, jmpbuf, true);
   __ Trap();
   __ bind(&resume);
+  __ endbr64();
   __ LeaveFrame(StackFrame::STACK_SWITCH);
   __ ret(0);
 }
@@ -4310,6 +4315,7 @@ void Generate_WasmResumeHelper(MacroAssembler* masm, w
   }
   __ Trap();
   __ bind(&suspend);
+  __ endbr64();
   __ LeaveFrame(StackFrame::STACK_SWITCH);
   // Pop receiver + parameter.
   __ ret(2 * kSystemPointerSize);
