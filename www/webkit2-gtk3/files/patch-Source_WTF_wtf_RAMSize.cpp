--- Source/WTF/wtf/RAMSize.cpp.orig	2020-08-12 09:17:54 UTC
+++ Source/WTF/wtf/RAMSize.cpp
@@ -34,6 +34,10 @@
 #if OS(LINUX)
 #include <sys/sysinfo.h>
 #endif // OS(LINUX)
+#if OS(FREEBSD)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 #else
 #include <bmalloc/bmalloc.h>
 #endif
@@ -54,10 +58,18 @@ static size_t computeRAMSize()
         return ramSizeGuess;
     return status.ullTotalPhys;
 #elif USE(SYSTEM_MALLOC)
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX)
     struct sysinfo si;
     sysinfo(&si);
     return si.totalram * si.mem_unit;
+#elif OS(FREEBSD)
+    size_t physmem, len;
+    int mib[2] = { CTL_HW, HW_PHYSMEM };
+    if (sysctl(mib, 2, &physmem, &len, NULL, 0) == 0
+        && len == sizeof(physmem))
+        return physmem;
+    else
+        return 512 * MB; // guess
 #else
 #error "Missing a platform specific way of determining the available RAM"
 #endif // OS(LINUX) || OS(FREEBSD)
