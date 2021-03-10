--- src/ogdf/basic/System.cpp.orig	2020-02-09 22:05:19 UTC
+++ src/ogdf/basic/System.cpp
@@ -56,6 +56,13 @@
 #include <mach/vm_statistics.h>
 #include <mach/mach.h>
 #include <mach/machine.h>
+#elif defined(OGDF_SYSTEM_FREEBSD)
+#include <stdlib.h>
+#include <unistd.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/time.h>
+#include <sys/resource.h>
 #elif defined(OGDF_SYSTEM_UNIX)
 #include <malloc.h>
 #endif
@@ -67,7 +74,7 @@
 # include <fcntl.h>
 # include <sys/time.h>
 #endif
-#ifdef __GNUC__
+#if defined(__GNUC__) && (defined(__amd64__) || defined(__i386__))
 # include <cpuid.h>
 #endif
 
@@ -81,7 +88,7 @@ static inline void cpuid(int CPUInfo[4], int infoType)
 	uint32_t c = 0;
 	uint32_t d = 0;
 
-# ifdef __GNUC__
+#if defined(__GNUC__) && (defined(__amd64__) || defined(__i386__))
 	__get_cpuid(infoType, &a, &b, &c, &d);
 # endif
 
@@ -289,6 +296,40 @@ size_t System::memoryUsedByProcess()
 	return 0;
 }
 
+#elif defined(OGDF_SYSTEM_FREEBSD)
+
+long long System::physicalMemory()
+{
+       unsigned long value;
+       size_t  size = sizeof( value );
+       if (sysctlbyname("hw.physmem", (void *)&value, &size, NULL, 0) != -1)
+               return value;
+       else
+               return 0;
+}
+
+long long System::availablePhysicalMemory()
+{
+       int pageSize = getpagesize ();
+       unsigned long result;
+    size_t size = sizeof (result);
+
+       if (sysctlbyname("vm.stats.vm.v_free_count", (void *)&result, &size, NULL, 0) != -1)
+        return result * pageSize;
+    else
+        return 0;
+}
+
+
+size_t System::memoryUsedByProcess()
+{
+    struct rusage r;
+    if (getrusage(RUSAGE_SELF, &r) != -1)
+        return r.ru_maxrss;
+    else
+        return 0;
+}
+
 #else
 // LINUX, NOT MAC OS
 long long System::physicalMemory()
@@ -370,6 +411,19 @@ size_t System::memoryInFreelistOfMalloc()
 {
 	return mstats().bytes_free;
 }
+
+#elif defined(OGDF_SYSTEM_FREEBSD)
+
+size_t System::memoryAllocatedByMalloc()
+{
+       return 0;
+}
+
+size_t System::memoryInFreelistOfMalloc()
+{
+       return 0;
+}
+
 #else
 
 size_t System::memoryAllocatedByMalloc()
