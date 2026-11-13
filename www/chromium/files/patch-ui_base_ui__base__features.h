--- ui/base/ui_base_features.h.orig	2026-11-11 14:44:17 UTC
+++ ui/base/ui_base_features.h
@@ -159,7 +159,7 @@ COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kWaylandExternalBeginFrameSource);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kGlobalShortcutsPortalPreferredTrigger);
 #endif
@@ -353,7 +353,7 @@ BASE_DECLARE_FEATURE(kChromeDarkNeutrals26);
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kDarkModeSurfaceTokens);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // When enabled, reads the system accent color from the xdg-desktop-portal (the
 // org.freedesktop.appearance "accent-color" setting) and applies it as the
 // NativeTheme user color.
