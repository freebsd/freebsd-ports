--- third_party/test_fonts/fontconfig/fontconfig_util_linux.cc.orig	2022-01-21 16:58:00 UTC
+++ third_party/test_fonts/fontconfig/fontconfig_util_linux.cc
@@ -12,13 +12,26 @@
 #include <climits>
 #include <string>
 
+#include "build/build_config.h"
+
+#if defined(OS_BSD)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 namespace test_fonts {
 
 std::string GetSysrootDir() {
   char buf[PATH_MAX + 1];
+#if defined(OS_BSD)
+  int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+  size_t cb = sizeof(buf);
+  assert(sysctl(mib, 4, buf, &cb, nullptr, 0) == 0);
+#else
   auto count = readlink("/proc/self/exe", buf, PATH_MAX);
   assert(count > 0);
   buf[count] = '\0';
+#endif
   return dirname(buf);
 }
 
