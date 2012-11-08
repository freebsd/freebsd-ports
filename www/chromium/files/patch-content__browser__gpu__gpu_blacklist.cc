--- content/browser/gpu/gpu_blacklist.cc.orig	2012-04-29 20:49:40.000000000 +0300
+++ content/browser/gpu/gpu_blacklist.cc	2012-04-29 20:49:54.000000000 +0300
@@ -940,7 +940,7 @@
   return kOsChromeOS;
 #elif defined(OS_WIN)
   return kOsWin;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kOsLinux;
 #elif defined(OS_MACOSX)
   return kOsMacosx;
