--- src/3rdparty/gn/src/util/sys_info.cc.orig	2026-05-08 07:54:08 UTC
+++ src/3rdparty/gn/src/util/sys_info.cc
@@ -74,6 +74,8 @@ std::string OperatingSystemArchitecture() {
     arch = "x86_64";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "powerpc") {
+    arch = "ppc64";
   } else if (os == "AIX" || os == "OS400") {
     arch = "ppc64";
   } else if (std::string(info.sysname) == "OS/390") {
