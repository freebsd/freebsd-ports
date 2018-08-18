--- base/sys_info_freebsd.cc.orig	2017-12-15 02:04:05.000000000 +0100
+++ base/sys_info_freebsd.cc	2017-12-23 21:51:22.626194000 +0100
@@ -13,26 +13,58 @@
 namespace base {
 
 int64_t SysInfo::AmountOfPhysicalMemoryImpl() {
-  int pages, page_size;
+  int pages, page_size, r = 0;
   size_t size = sizeof(pages);
-  sysctlbyname("vm.stats.vm.v_page_count", &pages, &size, NULL, 0);
-  sysctlbyname("vm.stats.vm.v_page_size", &page_size, &size, NULL, 0);
-  if (pages == -1 || page_size == -1) {
+  if(r == 0)
+    r = sysctlbyname("vm.stats.vm.v_page_count", &pages, &size, NULL, 0);
+  if(r == 0)
+    r =sysctlbyname("vm.stats.vm.v_page_size", &page_size, &size, NULL, 0);
+  if(r == -1) {
     NOTREACHED();
     return 0;
   }
   return static_cast<int64_t>(pages) * page_size;
 }
 
-// static
-uint64_t SysInfo::MaxSharedMemorySize() {
-  size_t limit;
-  size_t size = sizeof(limit);
-  if (sysctlbyname("kern.ipc.shmmax", &limit, &size, NULL, 0) < 0) {
+int64_t SysInfo::AmountOfAvailablePhysicalMemoryImpl() {
+  int page_size, r = 0;
+  unsigned pgfree, pginact, pgcache;
+  size_t size = sizeof(page_size);
+  size_t szpg = sizeof(pgfree);
+  if(r == 0)
+    r = sysctlbyname("vm.stats.vm.v_page_size", &page_size, &size, NULL, 0);
+  if(r == 0)
+    r = sysctlbyname("vm.stats.vm.v_free_count", &pgfree, &szpg, NULL, 0);
+  if(r == 0)
+    r = sysctlbyname("vm.stats.vm.v_inactive_count", &pginact, &szpg, NULL, 0);
+  if(r == 0)
+    r = sysctlbyname("vm.stats.vm.v_cache_count", &pgcache, &szpg, NULL, 0);
+  if(r == -1) {
     NOTREACHED();
     return 0;
   }
-  return static_cast<uint64_t>(limit);
+  return static_cast<int64_t>((pgfree + pginact + pgcache) * page_size);
+}
+
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
 }
 
 }  // namespace base
