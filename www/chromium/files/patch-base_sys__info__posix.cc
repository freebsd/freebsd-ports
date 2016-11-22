--- base/sys_info_posix.cc.orig	2016-08-03 22:02:10.000000000 +0300
+++ base/sys_info_posix.cc	2016-09-24 01:27:31.548122000 +0300
@@ -30,7 +30,7 @@
 
 namespace {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 int NumberOfProcessors() {
   // sysconf returns the number of "logical" (not "physical") processors on both
   // Mac and Linux.  So we get the number of max available "logical" processors.
@@ -77,7 +77,7 @@
 
 namespace base {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 int SysInfo::NumberOfProcessors() {
   return g_lazy_number_of_processors.Get().value();
 }
