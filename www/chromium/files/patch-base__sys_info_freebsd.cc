--- base/sys_info_freebsd.cc.orig	2012-10-31 21:02:04.000000000 +0200
+++ base/sys_info_freebsd.cc	2012-11-07 17:49:20.000000000 +0200
@@ -33,4 +33,25 @@
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
