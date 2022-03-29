commit 913cfc8ce77818fa44f9086ee44538337930a9ef
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>
Date:   Mon Mar 28 21:54:35 2022 +0200

    FreeBSD can use sched_getcpu() from 1400046/1300524 on

diff --git tools/profiler/core/platform.cpp tools/profiler/core/platform.cpp
index 92bcc1100687..77285f67b62c 100644
--- tools/profiler/core/platform.cpp
+++ tools/profiler/core/platform.cpp
@@ -111,6 +111,17 @@
 #  include <cpuid.h>
 #endif
 
+#if defined(GP_OS_freebsd)
+#include <sys/param.h>
+// "after making CPU_SET macros compatible with glibc"
+#  if __FreeBSD_version > 1400045 || (__FreeBSD_version > 1300523 && __FreeBSD_version < 1400000)
+#  include <sched.h>
+#  else
+// similar cpuid_count() trick as on Darwin, using LLVM
+#  include <cpuid.h>
+#  endif
+#endif
+
 #if defined(GP_OS_windows)
 #  include <processthreadsapi.h>
 
@@ -6368,6 +6379,19 @@ void profiler_mark_thread_awake() {
     cpuId = ebx >> 24;
   }
 #  endif
+#elif defined(GP_OS_freebsd) 
+#  if __FreeBSD_version > 1400045 || (__FreeBSD_version > 1300523 && __FreeBSD_version < 1400000)
+  cpuId = sched_getcpu();
+#  elif defined(__amd64__)
+  unsigned int eax, ebx, ecx, edx;
+  __cpuid_count(1, 0, eax, ebx, ecx, edx);
+  // Check if we have an APIC.
+  if ((edx & (1 << 9))) {
+    // APIC ID is bits 24-31 of EBX
+    cpuId = ebx >> 24;
+  }
+#  endif
+// the fallthrough is cpuID = 0
 #else
   cpuId = sched_getcpu();
 #endif
