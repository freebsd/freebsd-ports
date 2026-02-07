--- app/mma/src/linux/mma_linux.cpp.orig	2024-09-08 02:28:28 UTC
+++ app/mma/src/linux/mma_linux.cpp
@@ -44,6 +44,13 @@
 #include <pwd.h>
 #include <unistd.h>
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <stdio.h>
+#include <stdlib.h>
+#endif
+
 #include "../include/linux/mma_linux.h"
 
 #define B_IN_KB 1024.0
@@ -632,7 +639,18 @@ int MMALinux::GetCpuCores(void)
 
 int MMALinux::GetCpuCores(void)
 {
+#if defined(__FreeBSD__)
+  static int name[2] = {CTL_HW, HW_NCPU};
+  int32_t ncpu;
+  size_t size = sizeof(ncpu);
+  if (sysctl(name, sizeof(name)/sizeof(*name), &ncpu, &size, NULL, 0)) {
+    perror("unable to determine number of CPUs");
+    abort();
+  }
+  return (int)ncpu;
+#else
   return get_nprocs();
+#endif
 }
 
 std::string MMALinux::GetOsName()
