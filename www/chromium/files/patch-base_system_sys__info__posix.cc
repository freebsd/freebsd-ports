--- base/system/sys_info_posix.cc.orig	2020-11-13 06:36:34 UTC
+++ base/system/sys_info_posix.cc
@@ -223,6 +223,8 @@ std::string SysInfo::OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
