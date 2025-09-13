--- ui/gfx/switches.h.orig	2025-09-11 13:19:19 UTC
+++ ui/gfx/switches.h
@@ -19,7 +19,7 @@ GFX_SWITCHES_EXPORT extern const char kForcePrefersNoR
 GFX_SWITCHES_EXPORT extern const char kHeadless[];
 GFX_SWITCHES_EXPORT extern const char kScreenInfo[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 GFX_SWITCHES_EXPORT extern const char kX11Display[];
 GFX_SWITCHES_EXPORT extern const char kNoXshm[];
 #endif
