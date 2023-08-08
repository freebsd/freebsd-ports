--- src/3rdparty/chromium/base/system/sys_info_posix.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/base/system/sys_info_posix.cc
@@ -223,6 +223,8 @@ std::string SysInfo::OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
