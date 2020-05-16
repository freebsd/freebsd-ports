--- Source/JavaScriptCore/heap/MachineStackMarker.cpp.orig	2020-05-03 17:05:08 UTC
+++ Source/JavaScriptCore/heap/MachineStackMarker.cpp
@@ -86,7 +86,7 @@ static void pthreadSignalHandlerSuspendResume(int, sig
     }
 
     ucontext_t* userContext = static_cast<ucontext_t*>(ucontext);
-#if CPU(PPC)
+#if CPU(PPC) && defined(WTF_OS_LINUX)
     thread->suspendedMachineContext = *userContext->uc_mcontext.uc_regs;
 #else
     thread->suspendedMachineContext = userContext->uc_mcontext;
