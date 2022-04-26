--- chrome/browser/ui/color/native_chrome_color_mixer.cc.orig	2022-03-25 21:59:56 UTC
+++ chrome/browser/ui/color/native_chrome_color_mixer.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_WIN)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD)
 void AddNativeChromeColorMixer(ui::ColorProvider* provider,
                                const ui::ColorProviderManager::Key& key) {}
 #endif
