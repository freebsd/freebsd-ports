--- base/debug/stack_trace_posix.cc.orig	2021-12-14 11:44:55 UTC
+++ base/debug/stack_trace_posix.cc
@@ -35,7 +35,7 @@
 #include <AvailabilityMacros.h>
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/debug/proc_maps_linux.h"
 #endif
 
@@ -446,7 +446,7 @@ void StackDumpSignalHandler(int signal, siginfo_t* inf
   if (::signal(signal, SIG_DFL) == SIG_ERR) {
     _exit(EXIT_FAILURE);
   }
-#elif !defined(OS_LINUX)
+#elif !defined(OS_LINUX) && !defined(OS_BSD)
   // For all operating systems but Linux we do not reraise the signal that
   // brought us here but terminate the process immediately.
   // Otherwise various tests break on different operating systems, see
@@ -454,7 +454,7 @@ void StackDumpSignalHandler(int signal, siginfo_t* inf
   PrintToStderr(
       "Calling _exit(EXIT_FAILURE). Core file will not be generated.\n");
   _exit(EXIT_FAILURE);
-#endif  // !defined(OS_LINUX)
+#endif  // !defined(OS_LINUX) && !defined(OS_BSD)
 
   // After leaving this handler control flow returns to the point where the
   // signal was raised, raising the current signal once again but executing the
@@ -695,13 +695,21 @@ class SandboxSymbolizeHelper {
     // Reads /proc/self/maps.
     std::string contents;
     if (!ReadProcMaps(&contents)) {
+#if defined(OS_BSD)
+      LOG(ERROR) << "Failed to read /proc/curproc/map";
+#else
       LOG(ERROR) << "Failed to read /proc/self/maps";
+#endif
       return false;
     }
 
     // Parses /proc/self/maps.
     if (!ParseProcMaps(contents, &regions_)) {
+#if defined(OS_BSD)
+      LOG(ERROR) << "Failed to parse the contents of /proc/curproc/map";
+#else
       LOG(ERROR) << "Failed to parse the contents of /proc/self/maps";
+#endif
       return false;
     }
 
@@ -732,7 +740,11 @@ class SandboxSymbolizeHelper {
           // Skip regions with empty file names.
           continue;
         }
+#if defined(OS_BSD)
+	if (region.path[0] == '-') {
+#else	
         if (region.path[0] == '[') {
+#endif
           // Skip pseudo-paths, like [stack], [vdso], [heap], etc ...
           continue;
         }
@@ -827,9 +839,9 @@ bool EnableInProcessStackDumping() {
   success &= (sigaction(SIGBUS, &action, nullptr) == 0);
   success &= (sigaction(SIGSEGV, &action, nullptr) == 0);
 // On Linux, SIGSYS is reserved by the kernel for seccomp-bpf sandboxing.
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
   success &= (sigaction(SIGSYS, &action, nullptr) == 0);
-#endif  // !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 
   return success;
 }
