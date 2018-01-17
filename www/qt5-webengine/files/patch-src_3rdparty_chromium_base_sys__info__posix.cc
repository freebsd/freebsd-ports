--- src/3rdparty/chromium/base/sys_info_posix.cc.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/sys_info_posix.cc
@@ -35,7 +35,7 @@
 
 namespace {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 int NumberOfProcessors() {
   // sysconf returns the number of "logical" (not "physical") processors on both
   // Mac and Linux.  So we get the number of max available "logical" processors.
@@ -128,7 +128,7 @@ bool GetDiskSpaceInfo(const base::FilePa
 
 namespace base {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 int SysInfo::NumberOfProcessors() {
   return g_lazy_number_of_processors.Get().value();
 }
