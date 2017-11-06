--- xbmc/cores/VideoPlayer/Process/overrides/linux/ProcessInfoLinux.cpp.orig	2017-03-04 19:48:40 UTC
+++ xbmc/cores/VideoPlayer/Process/overrides/linux/ProcessInfoLinux.cpp
@@ -22,7 +22,7 @@
 #include "threads/SingleLock.h"
 
 // Override for platform ports
-#if defined(TARGET_LINUX)
+#if defined(TARGET_LINUX) || defined(TARGET_FREEBSD)
 
 CProcessInfo* CProcessInfo::CreateInstance()
 {
