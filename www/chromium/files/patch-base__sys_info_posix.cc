--- base/sys_info_posix.cc.orig	2014-10-02 17:39:45 UTC
+++ base/sys_info_posix.cc
@@ -64,7 +64,7 @@
 
 namespace base {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
 int SysInfo::NumberOfProcessors() {
   return g_lazy_number_of_processors.Get().value();
 }
