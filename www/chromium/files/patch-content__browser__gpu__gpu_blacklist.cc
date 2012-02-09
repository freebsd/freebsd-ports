--- content/browser/gpu/gpu_blacklist.cc.orig	2012-02-01 21:23:10.000000000 +0200
+++ content/browser/gpu/gpu_blacklist.cc	2012-02-01 21:23:18.000000000 +0200
@@ -817,7 +817,7 @@
   return kOsChromeOS;
 #elif defined(OS_WIN)
   return kOsWin;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kOsLinux;
 #elif defined(OS_MACOSX)
   return kOsMacosx;
