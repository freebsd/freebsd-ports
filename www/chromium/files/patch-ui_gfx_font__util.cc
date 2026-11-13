--- ui/gfx/font_util.cc.orig	2026-11-11 14:44:17 UTC
+++ ui/gfx/font_util.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 #include "skia/ext/font_utils.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <fontconfig/fontconfig.h>
 
 #include "base/check.h"
@@ -29,7 +29,7 @@ void InitializeFonts() {
   // background (resources have not yet been granted to cast) since it prevents
   // the long delay the user would have seen on first rendering.
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kAsyncFontconfigInitialization)) {
     // Early initialize FontConfig.
     InitializeGlobalFontConfigAsync();
