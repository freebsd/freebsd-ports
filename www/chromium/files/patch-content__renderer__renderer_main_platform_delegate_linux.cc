--- ./content/renderer/renderer_main_platform_delegate_linux.cc.orig	2014-08-20 21:02:43.000000000 +0200
+++ ./content/renderer/renderer_main_platform_delegate_linux.cc	2014-08-22 15:06:26.000000000 +0200
@@ -40,6 +40,7 @@
 }
 
 bool RendererMainPlatformDelegate::EnableSandbox() {
+#if !defined(OS_BSD)
   // The setuid sandbox is started in the zygote process: zygote_main_linux.cc
   // http://code.google.com/p/chromium/wiki/LinuxSUIDSandbox
   //
@@ -70,7 +71,7 @@
     CHECK_EQ(errno, EPERM);
   }
 #endif  // __x86_64__
-
+#endif  // ! OS_BSD
   return true;
 }
 
