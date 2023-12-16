--- src/3rdparty/chromium/ui/gfx/switches.h.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/ui/gfx/switches.h
@@ -19,7 +19,7 @@ GFX_SWITCHES_EXPORT extern const char kEnableNativeGpu
 GFX_SWITCHES_EXPORT extern const char kForcePrefersReducedMotion[];
 GFX_SWITCHES_EXPORT extern const char kHeadless[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 GFX_SWITCHES_EXPORT extern const char kX11Display[];
 GFX_SWITCHES_EXPORT extern const char kNoXshm[];
 #endif
