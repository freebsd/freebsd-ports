--- third_party/googletest/src/googletest/src/gtest-port.cc.orig	2019-03-11 22:08:00 UTC
+++ third_party/googletest/src/googletest/src/gtest-port.cc
@@ -55,6 +55,11 @@
 # include <mach/vm_map.h>
 #endif  // GTEST_OS_MAC
 
+#if GTEST_OS_FREEBSD
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
+
 #if GTEST_OS_QNX
 # include <devctl.h>
 # include <fcntl.h>
@@ -129,6 +134,28 @@ size_t GetThreadCount() {
   } else {
     return 0;
   }
+}
+
+#elif GTEST_OS_FREEBSD
+
+#define KP_NLWP(kp) (kp.ki_numthreads)
+
+// Return the number of threads running in the process, or 0 to indicate that
+// we cannot detect it.
+size_t GetThreadCount() {
+  int mib[] = {
+    CTL_KERN,
+    KERN_PROC,
+    KERN_PROC_PID,
+    getpid(),
+  };
+  u_int miblen = sizeof(mib) / sizeof(mib[0]);
+  struct kinfo_proc(info);
+  size_t size = sizeof(info);
+  if (sysctl(mib, miblen, &info, &size, NULL, 0)) {
+    return 0;
+  }
+  return KP_NLWP(info);
 }
 
 #elif GTEST_OS_QNX
