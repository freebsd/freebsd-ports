--- src/3rdparty/chromium/ui/gfx/font_util.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/gfx/font_util.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <fontconfig/fontconfig.h>
 #include "ui/gfx/linux/fontconfig_util.h"
 #endif
@@ -24,7 +24,7 @@ void InitializeFonts() {
   // background (resources have not yet been granted to cast) since it prevents
   // the long delay the user would have seen on first rendering.
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Early initialize FontConfig.
   InitializeGlobalFontConfigAsync();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
