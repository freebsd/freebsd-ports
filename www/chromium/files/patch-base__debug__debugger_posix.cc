--- base/debug/debugger_posix.cc.orig	2011-02-03 10:01:35.000000000 +0100
+++ base/debug/debugger_posix.cc	2011-02-06 17:07:57.000000000 +0100
@@ -15,6 +15,7 @@
 #include <sys/sysctl.h>
 #endif
 #include <sys/types.h>
+#include <sys/user.h>
 #include <unistd.h>
 
 #include <string>
@@ -50,7 +51,7 @@
   return false;
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 
 // Based on Apple's recommended method as described in
 // http://developer.apple.com/qa/qa2004/qa1361.html
@@ -88,7 +89,11 @@
 
   // This process is being debugged if the P_TRACED flag is set.
   is_set = true;
+#if defined(OS_FREEBSD)
+  being_debugged = (info.ki_flag & P_TRACED) != 0;
+#else
   being_debugged = (info.kp_proc.p_flag & P_TRACED) != 0;
+#endif
   return being_debugged;
 }
 
@@ -135,15 +140,7 @@
   return false;
 }
 
-#elif defined(OS_FREEBSD)
-
-bool BeingDebugged() {
-  // TODO(benl): can we determine this under FreeBSD?
-  NOTIMPLEMENTED();
-  return false;
-}
-
-#endif  // defined(OS_FREEBSD)
+#endif
 
 // We want to break into the debugger in Debug mode, and cause a crash dump in
 // Release mode. Breakpad behaves as follows:
