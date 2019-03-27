--- src/3rdparty/chromium/content/renderer/renderer_main.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/renderer/renderer_main.cc
@@ -177,7 +177,7 @@ int RendererMain(const MainFunctionParams& parameters)
     bool need_sandbox =
         !command_line.HasSwitch(service_manager::switches::kNoSandbox);
 
-#if !defined(OS_WIN) && !defined(OS_MACOSX)
+#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_BSD)
     // Sandbox is enabled before RenderProcess initialization on all platforms,
     // except Windows and Mac.
     // TODO(markus): Check if it is OK to remove ifdefs for Windows and Mac.
