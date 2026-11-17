--- src/third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc.orig	2026-10-18 18:43:23 UTC
+++ src/third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc
@@ -123,7 +123,7 @@ bool ScrollbarThemeAura::SupportsDragSna
 // Disable snapback on desktop Linux to better integrate with the desktop
 // behavior. Typically, Linux apps do not implement scrollbar snapback (this
 // is true for at least GTK and QT apps).
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
@@ -385,7 +385,7 @@ ScrollbarPart ScrollbarThemeAura::PartsT
 
 bool ScrollbarThemeAura::ShouldCenterOnThumb(const Scrollbar& scrollbar,
                                              const WebMouseEvent& event) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event.button == WebPointerProperties::Button::kMiddle)
     return true;
 #endif
