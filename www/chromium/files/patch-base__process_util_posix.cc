--- ./base/process_util_posix.cc.orig	2010-12-16 02:11:49.000000000 +0100
+++ ./base/process_util_posix.cc	2010-12-20 20:15:08.000000000 +0100
@@ -102,11 +102,11 @@
   return status;
 }
 
-void StackDumpSignalHandler(int signal, siginfo_t* info, ucontext_t* context) {
+void StackDumpSignalHandler(int signal, siginfo_t* info /*, ucontext_t* context */) {
   LOG(ERROR) << "Received signal " << signal;
   debug::StackTrace().PrintBacktrace();
 
-  // TODO(shess): Port to Linux.
+  // TODO(shess): Port to Linux and FreeBSD.
 #if defined(OS_MACOSX)
   // TODO(shess): Port to 64-bit.
 #if ARCH_CPU_32_BITS
