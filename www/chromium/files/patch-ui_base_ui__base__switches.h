--- ui/base/ui_base_switches.h.orig	2024-08-26 12:06:38 UTC
+++ ui/base/ui_base_switches.h
@@ -27,11 +27,11 @@ COMPONENT_EXPORT(UI_BASE) extern const char kShowMacOv
 COMPONENT_EXPORT(UI_BASE) extern const char kEnableResourcesFileSharing[];
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE) extern const char kSystemFontFamily[];
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE) extern const char kUiToolkitFlag[];
 COMPONENT_EXPORT(UI_BASE) extern const char kDisableGtkIme[];
 #endif
