--- ./gpu/config/gpu_control_list.cc.orig	2014-04-30 22:41:33.000000000 +0200
+++ ./gpu/config/gpu_control_list.cc	2014-05-04 14:38:48.000000000 +0200
@@ -1400,10 +1400,10 @@
   return kOsWin;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
-  return kOsLinux;
 #elif defined(OS_MACOSX)
   return kOsMacosx;
+#elif defined(OS_POSIX)
+  return kOsLinux;
 #else
   return kOsUnknown;
 #endif
