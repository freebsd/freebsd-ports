--- v8/src/builtins/x64/builtins-x64.cc.orig	2025-02-19 07:43:18 UTC
+++ v8/src/builtins/x64/builtins-x64.cc
@@ -1836,7 +1836,7 @@ static void Generate_InterpreterEnterBytecode(MacroAss
                   times_system_pointer_size, 0));
 
   // Jump to the interpreter entry, and call kJavaScriptCallCodeStartRegister.
-  __ jmp(rbx);
+  __ jmp(rbx, /*notrack=*/true);
 }
 
 void Builtins::Generate_InterpreterEnterAtNextBytecode(MacroAssembler* masm) {
