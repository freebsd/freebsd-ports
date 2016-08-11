--- base/sys_info_posix.cc.orig	2016-03-25 13:04:44 UTC
+++ base/sys_info_posix.cc
@@ -77,7 +77,7 @@ base::LazyInstance<
 
 namespace base {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
 int SysInfo::NumberOfProcessors() {
   return g_lazy_number_of_processors.Get().value();
 }
