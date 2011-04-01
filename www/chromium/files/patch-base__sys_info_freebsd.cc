--- base/sys_info_freebsd.cc.orig	2011-01-29 10:49:10.000000000 +0100
+++ base/sys_info_freebsd.cc	2011-02-07 22:02:40.000000000 +0100
@@ -30,4 +30,21 @@
   return limit;
 }
 
+int SysInfo::NumberOfProcessors() {
+  int mib[2];
+  
+  mib[0] = CTL_HW;
+  mib[1] = HW_NCPU;
+
+  int ncpu;
+  size_t len = sizeof(ncpu);
+
+  if (sysctl(mib, 2, &ncpu, &len, NULL, 0) == -1) {
+    NOTREACHED();
+    return 1;
+  }
+
+  return ncpu;
+}
+
 }  // namespace base
