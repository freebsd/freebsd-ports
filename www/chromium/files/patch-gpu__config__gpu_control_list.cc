--- gpu/config/gpu_control_list.cc.orig	2013-09-02 21:03:44.000000000 +0300
+++ gpu/config/gpu_control_list.cc	2013-09-02 21:05:31.000000000 +0300
@@ -1346,10 +1346,10 @@
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
