--- base/sys_info_posix.cc.orig	2017-07-25 21:04:48.000000000 +0200
+++ base/sys_info_posix.cc	2017-08-02 21:19:06.172695000 +0200
@@ -35,7 +35,7 @@
 
 namespace {
 
-#if !defined(OS_OPENBSD) && !defined(OS_FUCHSIA)
+#if !defined(OS_BSD) && !defined(OS_FUCHSIA)
 int NumberOfProcessors() {
   // sysconf returns the number of "logical" (not "physical") processors on both
   // Mac and Linux.  So we get the number of max available "logical" processors.
@@ -128,7 +128,7 @@
 
 namespace base {
 
-#if !defined(OS_OPENBSD) && !defined(OS_FUCHSIA)
+#if !defined(OS_BSD) && !defined(OS_FUCHSIA)
 int SysInfo::NumberOfProcessors() {
   return g_lazy_number_of_processors.Get().value();
 }
