--- base/system/sys_info_posix.cc.orig	2021-04-14 18:40:48 UTC
+++ base/system/sys_info_posix.cc
@@ -26,6 +26,11 @@
 #if defined(OS_ANDROID)
 #include <sys/vfs.h>
 #define statvfs statfs  // Android uses a statvfs-like statfs struct and call.
+#elif defined(OS_BSD)
+#include <sys/param.h>
+#include <sys/mount.h>
+#define statvfs statfs
+#define f_frsize f_bsize
 #else
 #include <sys/statvfs.h>
 #endif
@@ -239,6 +244,8 @@ std::string SysInfo::OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
