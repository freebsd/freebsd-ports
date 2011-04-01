--- base/sys_info_posix.cc.orig	2011-02-07 00:36:57.000000000 +0100
+++ base/sys_info_posix.cc	2011-02-07 00:21:53.000000000 +0100
@@ -23,7 +23,7 @@
 
 namespace base {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
 int SysInfo::NumberOfProcessors() {
   // It seems that sysconf returns the number of "logical" processors on both
   // Mac and Linux.  So we get the number of "online logical" processors.
