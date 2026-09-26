--- chrome/common/chrome_switches.h.orig	2026-09-25 15:26:43 UTC
+++ chrome/common/chrome_switches.h
@@ -976,7 +976,7 @@ inline constexpr char kDebugPrint[] = "debug-print";
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Causes the browser to launch directly in guest mode.
 inline constexpr char kGuest[] = "guest";
 
@@ -1044,7 +1044,7 @@ inline constexpr char kGlicGuestUrlPresetPreprod[] =
 
 inline constexpr char kGlicGuestUrlPresetProd[] = "glic-guest-url-preset-prod";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Writes open and installed web apps for each profile to the specified file
 // without launching a new browser window or tab. Pass a absolute file path
 // to specify where to output the information. Can be used together with
