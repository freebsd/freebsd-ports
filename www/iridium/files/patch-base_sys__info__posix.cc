--- base/sys_info_posix.cc.orig	2018-01-04 21:05:38.000000000 +0100
+++ base/sys_info_posix.cc	2018-01-27 20:03:02.391851000 +0100
@@ -35,7 +35,7 @@
 
 namespace {
 
-#if !defined(OS_OPENBSD) && !defined(OS_FUCHSIA)
+#if !defined(OS_BSD) && !defined(OS_FUCHSIA)
 int NumberOfProcessors() {
   // sysconf returns the number of "logical" (not "physical") processors on both
   // Mac and Linux.  So we get the number of max available "logical" processors.
@@ -62,7 +62,7 @@
 base::LazyInstance<
     base::internal::LazySysInfoValue<int, NumberOfProcessors> >::Leaky
     g_lazy_number_of_processors = LAZY_INSTANCE_INITIALIZER;
-#endif  // !defined(OS_OPENBSD) && !defined(OS_FUCHSIA)
+#endif  // !defined(OS_BSD) && !defined(OS_FUCHSIA)
 
 #if !defined(OS_FUCHSIA)
 int64_t AmountOfVirtualMemory() {
@@ -130,7 +130,7 @@
 
 namespace base {
 
-#if !defined(OS_OPENBSD) && !defined(OS_FUCHSIA)
+#if !defined(OS_BSD) && !defined(OS_FUCHSIA)
 int SysInfo::NumberOfProcessors() {
   return g_lazy_number_of_processors.Get().value();
 }
@@ -223,6 +223,8 @@
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
