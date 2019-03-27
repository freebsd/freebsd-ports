--- src/3rdparty/gn/util/exe_path.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/gn/util/exe_path.cc
@@ -13,6 +13,9 @@
 #include <mach-o/dyld.h>
 #elif defined(OS_WIN)
 #include <windows.h>
+#elif defined(OS_FREEBSD)
+#include <sys/param.h>
+#include <sys/sysctl.h>
 #endif
 
 #if defined(OS_MACOSX)
@@ -44,6 +47,20 @@ base::FilePath GetExePath() {
     return base::FilePath();
   }
   return base::FilePath(system_buffer);
+}
+
+#elif defined(OS_FREEBSD)
+
+base::FilePath GetExePath() {
+  int name[] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+  char system_buffer[PATH_MAX + 1];
+  size_t length = sizeof(system_buffer);
+  int error = sysctl(name, 4, system_buffer, &length, NULL, 0);
+  if (error < 0 || length <= 1) {
+    NOTREACHED() << "Unable to resolve path.";
+    return base::FilePath();
+  }
+  return base::FilePath(base::FilePath::StringType(system_buffer, length - 1));
 }
 
 #else
