--- src/3rdparty/chromium/ui/color/native_color_mixers.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/color/native_color_mixers.cc
@@ -10,12 +10,12 @@ namespace ui {
 namespace ui {
 
 #if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && \
-    !BUILDFLAG(IS_WIN)
+    !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD)
 void AddNativeCoreColorMixer(ColorProvider* provider,
                              const ColorProviderManager::Key& key) {}
 #endif
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_WIN)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD)
 void AddNativeUiColorMixer(ColorProvider* provider,
                            const ColorProviderManager::Key& key) {}
 #endif
