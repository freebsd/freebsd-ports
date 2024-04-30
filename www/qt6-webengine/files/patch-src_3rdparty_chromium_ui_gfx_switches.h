--- src/3rdparty/chromium/ui/gfx/switches.h.orig	2023-07-16 15:47:57 UTC
+++ src/3rdparty/chromium/ui/gfx/switches.h
@@ -18,7 +18,7 @@ GFX_SWITCHES_EXPORT extern const char kEnableNativeGpu
 GFX_SWITCHES_EXPORT extern const char kForcePrefersReducedMotion[];
 GFX_SWITCHES_EXPORT extern const char kHeadless[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 GFX_SWITCHES_EXPORT extern const char kX11Display[];
 GFX_SWITCHES_EXPORT extern const char kNoXshm[];
 #endif
