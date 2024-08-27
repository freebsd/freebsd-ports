--- ui/base/ui_base_switches.cc.orig	2024-08-27 06:28:16 UTC
+++ ui/base/ui_base_switches.cc
@@ -31,13 +31,13 @@ const char kShowMacOverlayBorders[] = "show-mac-overla
 const char kEnableResourcesFileSharing[] = "enable-resources-file-sharing";
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
