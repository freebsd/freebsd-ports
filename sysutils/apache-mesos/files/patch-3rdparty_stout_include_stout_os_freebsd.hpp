--- 3rdparty/stout/include/stout/os/freebsd.hpp.orig	2020-05-22 20:48:06 UTC
+++ 3rdparty/stout/include/stout/os/freebsd.hpp
@@ -88,18 +88,29 @@ inline Try<Memory> memory()
   const size_t pageSize = os::pagesize();
 
   unsigned int freeCount;
-  size_t length = sizeof(freeCount);
-
+  size_t freeCountLength = sizeof(freeCount);
   if (sysctlbyname(
-      "vm.stats.v_free_count",
+      "vm.stats.vm.v_free_count",
       &freeCount,
-      &length,
+      &freeCountLength,
       nullptr,
       0) != 0) {
     return ErrnoError();
   }
-  memory.free = Bytes(freeCount * pageSize);
 
+  unsigned int inactiveCount;
+  size_t inactiveCountLength = sizeof(inactiveCount);
+  if (sysctlbyname(
+      "vm.stats.vm.v_inactive_count",
+      &inactiveCount,
+      &inactiveCountLength,
+      nullptr,
+      0) != 0) {
+    return ErrnoError();
+  }
+
+  memory.free = Bytes((freeCount + inactiveCount) * pageSize);
+
   int totalBlocks = 0;
   int usedBlocks = 0;
 
@@ -112,8 +123,9 @@ inline Try<Memory> memory()
   // FreeBSD supports multiple swap devices. Here we sum across all of them.
   struct xswdev xswd;
   size_t xswdSize = sizeof(xswd);
-  int* mibDevice = &(mib[mibSize + 1]);
-  for (*mibDevice = 0; ; (*mibDevice)++) {
+  for (int ndev = 0; ; ndev++) {
+      mib[mibSize] = ndev;
+
       if (::sysctl(mib, 3, &xswd, &xswdSize, nullptr, 0) != 0) {
           if (errno == ENOENT) {
               break;
