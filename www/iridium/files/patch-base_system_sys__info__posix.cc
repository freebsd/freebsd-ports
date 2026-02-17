--- base/system/sys_info_posix.cc.orig	2026-02-16 10:45:29 UTC
+++ base/system/sys_info_posix.cc
@@ -58,7 +58,11 @@ base::ByteSize AmountOfVirtualMemory() {
   if (result != 0) {
     NOTREACHED();
   }
+#if BUILDFLAG(IS_FREEBSD)
+  return base::ByteSize(limit.rlim_cur == RLIM_INFINITY ? 0 : base::checked_cast<uint64_t>(limit.rlim_cur));
+#else
   return base::ByteSize(limit.rlim_cur == RLIM_INFINITY ? 0 : limit.rlim_cur);
+#endif
 }
 using LazyVirtualMemory =
     base::internal::LazySysInfoValue<base::ByteSize, AmountOfVirtualMemory>;
@@ -140,7 +144,7 @@ void GetKernelVersionNumbers(int32_t* major_version,
 
 namespace base {
 
-#if !BUILDFLAG(IS_OPENBSD)
+#if !BUILDFLAG(IS_BSD)
 // static
 int SysInfo::NumberOfProcessors() {
 #if BUILDFLAG(IS_MAC)
@@ -196,7 +200,7 @@ int SysInfo::NumberOfProcessors() {
 
   return cached_num_cpus;
 }
-#endif  // !BUILDFLAG(IS_OPENBSD)
+#endif  // !BUILDFLAG(IS_BSD)
 
 // static
 ByteSize SysInfo::AmountOfVirtualMemory() {
@@ -286,6 +290,8 @@ std::string SysInfo::OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
