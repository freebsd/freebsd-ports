--- content/browser/gpu/gpu_blacklist.cc.orig	2012-12-20 10:01:26.000000000 +0200
+++ content/browser/gpu/gpu_blacklist.cc	2013-01-06 21:30:12.000000000 +0200
@@ -1348,7 +1348,7 @@
   return kOsWin;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kOsLinux;
 #elif defined(OS_MACOSX)
   return kOsMacosx;
