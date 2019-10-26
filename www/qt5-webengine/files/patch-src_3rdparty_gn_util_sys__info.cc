--- src/3rdparty/gn/util/sys_info.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/gn/util/sys_info.cc
@@ -28,6 +28,8 @@ std::string OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
