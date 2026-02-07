--- src/3rdparty/chromium/ui/base/ui_base_switches.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/base/ui_base_switches.cc
@@ -24,13 +24,13 @@ const char kShowMacOverlayBorders[] = "show-mac-overla
 const char kShowMacOverlayBorders[] = "show-mac-overlay-borders";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Specifies system font family name. Improves determenism when rendering
 // pages in headless mode.
 const char kSystemFontFamily[] = "system-font-family";
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Specify the toolkit used to construct the Linux GUI.
 const char kUiToolkitFlag[] = "ui-toolkit";
 // Disables GTK IME integration.
