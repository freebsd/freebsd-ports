--- tools/gn/src/util/sys_info.cc.orig	2020-11-13 06:49:31 UTC
+++ tools/gn/src/util/sys_info.cc
@@ -33,6 +33,8 @@ std::string OperatingSystemArchitecture() {
     arch = "x86_64";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
