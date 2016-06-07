--- content/renderer/renderer_main_platform_delegate_linux.cc.orig	2016-04-08 16:02:09 UTC
+++ content/renderer/renderer_main_platform_delegate_linux.cc
@@ -29,6 +29,7 @@ void RendererMainPlatformDelegate::Platf
 }
 
 bool RendererMainPlatformDelegate::EnableSandbox() {
+#if !defined(OS_BSD)
   // The setuid sandbox is started in the zygote process: zygote_main_linux.cc
   // https://chromium.googlesource.com/chromium/src/+/master/docs/linux_suid_sandbox.md
   //
@@ -59,7 +60,7 @@ bool RendererMainPlatformDelegate::Enabl
     CHECK_EQ(errno, EPERM);
   }
 #endif  // __x86_64__
-
+#endif  // ! OS_BSD
   return true;
 }
 
