commit 45a7951cb6a9b1735b9b6cec89db69b5933715c7
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>
Date:   Mon Mar 28 21:54:35 2022 +0200

    FreeBSD can use sched_getcpu() from 1400046/1300524 on

diff --git tools/profiler/core/platform.cpp tools/profiler/core/platform.cpp
index 92bcc1100687..2f17a88942a8 100644
--- tools/profiler/core/platform.cpp
+++ tools/profiler/core/platform.cpp
@@ -111,6 +111,20 @@
 #  include <cpuid.h>
 #endif
 
+#if defined(GP_OS_freebsd)
+#include <sys/param.h>
+// "after making CPU_SET macros compatible with glibc"
+#  if __FreeBSD_version > 1400045 || (__FreeBSD_version > 1300523 && __FreeBSD_version < 1400000)
+#  include <sched.h>
+#  else
+#    if __x86_64__ || __i386__
+// similar cpuid_count() trick as on Darwin, using LLVM
+// but not for all CPUs
+#      include <cpuid.h>
+#    endif
+#  endif
+#endif
+
 #if defined(GP_OS_windows)
 #  include <processthreadsapi.h>
 
@@ -6368,6 +6382,19 @@ void profiler_mark_thread_awake() {
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
