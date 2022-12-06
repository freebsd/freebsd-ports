--- base/system/sys_info_posix.cc.orig	2022-12-06 08:09:13 UTC
+++ base/system/sys_info_posix.cc
@@ -182,12 +182,12 @@ absl::optional<int> NumberOfPhysicalProcessors() {
 
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
@@ -277,6 +277,8 @@ std::string SysInfo::OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
@@ -300,4 +302,4 @@ void SysInfo::SetIsCpuSecurityMitigationsEnabled(bool 
 
 #endif  // BUILDFLAG(IS_MAC)
 
-}  // namespace base
\ No newline at end of file
+}  // namespace base
