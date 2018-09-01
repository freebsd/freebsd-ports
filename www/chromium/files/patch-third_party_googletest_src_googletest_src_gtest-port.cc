--- third_party/googletest/src/googletest/src/gtest-port.cc.orig	2018-08-23 02:39:24.119551000 +0200
+++ third_party/googletest/src/googletest/src/gtest-port.cc	2018-08-23 02:46:41.990204000 +0200
@@ -52,6 +52,11 @@
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
@@ -126,6 +131,28 @@
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
