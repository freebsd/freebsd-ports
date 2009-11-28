--- JavaScriptCore/jit/JITOpcodes.cpp.orig	2009-09-29 15:43:18.000000000 -0400
+++ JavaScriptCore/jit/JITOpcodes.cpp	2009-11-01 13:09:39.000000000 -0500
@@ -270,7 +270,7 @@ void JIT::privateCompileCTIMachineTrampo
     emitGetFromCallFrameHeaderPtr(RegisterFile::ReturnPC, regT1);
     move(ImmPtr(&globalData->exceptionLocation), regT2);
     storePtr(regT1, regT2);
-    move(ImmPtr(reinterpret_cast<void*>(ctiVMThrowTrampoline)), regT2);
+    move(ImmPtr((void*)(ctiVMThrowTrampoline)), regT2);
     emitGetFromCallFrameHeaderPtr(RegisterFile::CallerFrame, callFrameRegister);
     poke(callFrameRegister, OBJECT_OFFSETOF(struct JITStackFrame, callFrame) / sizeof (void*));
     restoreReturnAddressBeforeReturn(regT2);
@@ -1754,7 +1754,7 @@ void JIT::privateCompileCTIMachineTrampo
     emitGetFromCallFrameHeaderPtr(RegisterFile::ReturnPC, regT1);
     move(ImmPtr(&globalData->exceptionLocation), regT2);
     storePtr(regT1, regT2);
-    move(ImmPtr(reinterpret_cast<void*>(ctiVMThrowTrampoline)), regT2);
+    move(ImmPtr((void*)(ctiVMThrowTrampoline)), regT2);
     emitGetFromCallFrameHeaderPtr(RegisterFile::CallerFrame, callFrameRegister);
     poke(callFrameRegister, OBJECT_OFFSETOF(struct JITStackFrame, callFrame) / sizeof (void*));
     restoreReturnAddressBeforeReturn(regT2);
