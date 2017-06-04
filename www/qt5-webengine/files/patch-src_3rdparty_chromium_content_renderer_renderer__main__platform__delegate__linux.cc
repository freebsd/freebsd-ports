--- src/3rdparty/chromium/content/renderer/renderer_main_platform_delegate_linux.cc.orig	2017-04-20 13:24:44 UTC
+++ src/3rdparty/chromium/content/renderer/renderer_main_platform_delegate_linux.cc
@@ -29,6 +29,7 @@ void RendererMainPlatformDelegate::Platf
 }
 
 bool RendererMainPlatformDelegate::EnableSandbox() {
+#if defined(OS_LINUX)
   // The setuid sandbox is started in the zygote process: zygote_main_linux.cc
   // http://code.google.com/p/chromium/wiki/LinuxSUIDSandbox
   //
@@ -60,6 +61,7 @@ bool RendererMainPlatformDelegate::Enabl
   }
 #endif  // __x86_64__
 
+#endif  // defined(OS_LINUX)
   return true;
 }
 
