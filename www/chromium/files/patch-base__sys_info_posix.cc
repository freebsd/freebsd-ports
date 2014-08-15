--- ./base/sys_info_posix.cc.orig	2014-08-12 21:01:28.000000000 +0200
+++ ./base/sys_info_posix.cc	2014-08-13 09:56:56.000000000 +0200
@@ -64,7 +64,7 @@
 
 namespace base {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
 int SysInfo::NumberOfProcessors() {
   return g_lazy_number_of_processors.Get().value();
 }
