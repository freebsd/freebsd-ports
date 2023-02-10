--- base/system/sys_info_posix.cc.orig	2023-01-17 19:19:00 UTC
+++ base/system/sys_info_posix.cc
@@ -154,12 +154,12 @@ int NumberOfProcessors() {
 
 }  // namespace internal
 
-#if !BUILDFLAG(IS_OPENBSD)
+#if !BUILDFLAG(IS_BSD)
 int SysInfo::NumberOfProcessors() {
   static int number_of_processors = internal::NumberOfProcessors();
   return number_of_processors;
 }
-#endif  // !BUILDFLAG(IS_OPENBSD)
+#endif  // !BUILDFLAG(IS_BSD)
 
 // static
 uint64_t SysInfo::AmountOfVirtualMemory() {
@@ -249,6 +249,8 @@ std::string SysInfo::OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
