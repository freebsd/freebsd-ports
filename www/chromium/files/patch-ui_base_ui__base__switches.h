--- ui/base/ui_base_switches.h.orig	2026-11-19 12:25:27 UTC
+++ ui/base/ui_base_switches.h
@@ -33,13 +33,13 @@ inline constexpr char kDisableModalAnimations[] = "dis
 inline constexpr char kShowMacOverlayBorders[] = "show-mac-overlay-borders";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Specifies system font family name. Improves determinism when rendering pages
 // in headless mode.
 inline constexpr char kSystemFontFamily[] = "system-font-family";
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Specify the toolkit used to construct the Linux GUI.
 inline constexpr char kUiToolkitFlag[] = "ui-toolkit";
 // Specify the GTK version to be loaded.
