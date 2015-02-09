--- ./base/sys_info_posix.cc.orig	2014-04-30 22:41:43.000000000 +0200
+++ ./base/sys_info_posix.cc	2014-05-04 14:38:46.000000000 +0200
@@ -49,7 +49,7 @@
 
 namespace base {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
 int SysInfo::NumberOfProcessors() {
   return g_lazy_number_of_processors.Get().value();
 }
