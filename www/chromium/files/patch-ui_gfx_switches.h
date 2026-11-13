--- ui/gfx/switches.h.orig	2026-11-11 14:44:17 UTC
+++ ui/gfx/switches.h
@@ -19,7 +19,7 @@ GFX_SWITCHES_EXPORT extern const char kForcePrefersNoR
 GFX_SWITCHES_EXPORT extern const char kHeadless[];
 GFX_SWITCHES_EXPORT extern const char kScreenInfo[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 GFX_SWITCHES_EXPORT extern const char kX11Display[];
 GFX_SWITCHES_EXPORT extern const char kNoXshm[];
 #endif
@@ -43,7 +43,7 @@ GFX_SWITCHES_EXPORT BASE_DECLARE_FEATURE(kTransparentI
 // data.
 GFX_SWITCHES_EXPORT BASE_DECLARE_FEATURE(kHarfBuzzZeroCopyFontTable);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // When enabled, fontconfig initialization is done asynchronously on a worker
 // thread to prevent blocking browser startup. See https://crbug.com/41496758.
 GFX_SWITCHES_EXPORT BASE_DECLARE_FEATURE(kAsyncFontconfigInitialization);
