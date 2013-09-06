--- src/basic/System.cpp.orig	2013-06-10 17:33:24.000000000 +0200
+++ src/basic/System.cpp	2013-06-10 17:47:24.000000000 +0200
@@ -51,6 +51,13 @@
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
@@ -310,6 +317,40 @@
 	return 0;
 }
 
+#elif defined(OGDF_SYSTEM_FREEBSD)
+
+long long System::physicalMemory()
+{
+	unsigned long value;
+	size_t  size = sizeof( value );
+	if (sysctlbyname("hw.physmem", (void *)&value, &size, NULL, 0) != -1)
+		return value;
+	else 
+		return 0;
+}
+
+long long System::availablePhysicalMemory()
+{
+	int pageSize = getpagesize ();
+	unsigned long result;
+    size_t size = sizeof (result);
+
+	if (sysctlbyname("vm.stats.vm.v_free_count", (void *)&result, &size, NULL, 0) != -1)
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
@@ -396,6 +437,19 @@
 {
 	return mstats().chunks_free;
 }
+
+#elif defined(OGDF_SYSTEM_FREEBSD)
+
+size_t System::memoryAllocatedByMalloc()
+{
+	return 0;
+}
+
+size_t System::memoryInFreelistOfMalloc()
+{
+	return 0;
+}
+
 #else
 
 size_t System::memoryAllocatedByMalloc()
