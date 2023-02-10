--- base/system/sys_info_posix.cc.orig	2023-02-08 09:03:45 UTC
+++ base/system/sys_info_posix.cc
@@ -159,12 +159,12 @@ int NumberOfProcessors() {
 
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
@@ -254,6 +254,8 @@ std::string SysInfo::OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
