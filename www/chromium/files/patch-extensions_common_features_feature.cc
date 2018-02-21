--- extensions/common/features/feature.cc.orig	2018-01-21 13:38:52.998785000 +0100
+++ extensions/common/features/feature.cc	2018-01-21 13:39:29.946264000 +0100
@@ -26,6 +26,8 @@
   return MACOSX_PLATFORM;
 #elif defined(OS_WIN)
   return WIN_PLATFORM;
+#elif defined(OS_BSD)
+  return LINUX_PLATFORM;
 #else
   return UNSPECIFIED_PLATFORM;
 #endif
