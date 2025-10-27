--- ui/base/ui_base_switches.h.orig	2025-10-21 16:57:35 UTC
+++ ui/base/ui_base_switches.h
@@ -37,13 +37,13 @@ inline constexpr char kDisableModalAnimations[] = "dis
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
