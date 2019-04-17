--- tools/gn/util/sys_info.cc.orig	2019-04-04 13:16:59.443413000 +0200
+++ tools/gn/util/sys_info.cc	2019-04-04 13:17:14.281724000 +0200
@@ -28,6 +28,8 @@ std::string OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
