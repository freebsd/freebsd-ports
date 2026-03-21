--- content/renderer/renderer_main.cc.orig	2026-03-13 06:02:14 UTC
+++ content/renderer/renderer_main.cc
@@ -196,7 +196,7 @@ int RendererMain(MainFunctionParams parameters) {
 
   InitializeSkia();
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
   // On Linux, Windows, and ChromeOS, the font manager is overridden or
   // specially handled in RendererBlinkPlatformImpl(). On other platforms,
   // initialise the default one on a thread pool, to avoid blocking on it later.
