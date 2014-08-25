--- ./base/sys_info_freebsd.cc.orig	2014-04-30 22:41:43.000000000 +0200
+++ ./base/sys_info_freebsd.cc	2014-05-04 14:38:46.000000000 +0200
@@ -4,6 +4,7 @@
 
 #include "base/sys_info.h"
 
+#include <sys/types.h>
 #include <sys/sysctl.h>
 
 #include "base/logging.h"
@@ -23,6 +24,19 @@
 }
 
 // static
+int64 SysInfo::AmountOfAvailablePhysicalMemory() {
+  int available_pages, page_size;
+  size_t size = sizeof(available_pages);
+  sysctlbyname("vm.stats.vm.v_free_count", &available_pages, &size, NULL, 0);
+  sysctlbyname("vm.stats.vm.v_page_size", &page_size, &size, NULL, 0);
+  if (available_pages == -1 || page_size == -1) {
+    NOTREACHED();
+    return 0;
+  }
+  return static_cast<int64>(available_pages) * page_size;
+}
+
+// static
 size_t SysInfo::MaxSharedMemorySize() {
   size_t limit;
   size_t size = sizeof(limit);
@@ -33,4 +47,25 @@
   return limit;
 }
 
+// static
+std::string SysInfo::CPUModelName() {
+  int mib[] = { CTL_HW, HW_MODEL };
+  char name[256];
+  size_t size = arraysize(name);
+  if (sysctl(mib, arraysize(mib), &name, &size, NULL, 0) == 0)
+    return name;
+  return std::string();
+}
+
+int SysInfo::NumberOfProcessors() {
+  int mib[] = { CTL_HW, HW_NCPU };
+  int ncpu;
+  size_t size = sizeof(ncpu);
+  if (sysctl(mib, arraysize(mib), &ncpu, &size, NULL, 0) == -1) {
+    NOTREACHED();
+    return 1;
+  }
+  return ncpu;
+}
+
 }  // namespace base
