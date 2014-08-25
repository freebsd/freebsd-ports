--- ./gpu/config/gpu_control_list.cc.orig	2014-08-20 21:02:37.000000000 +0200
+++ ./gpu/config/gpu_control_list.cc	2014-08-22 15:06:26.000000000 +0200
@@ -1539,10 +1539,10 @@
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
