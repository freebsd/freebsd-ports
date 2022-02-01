--- third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc.orig	2021-12-31 00:57:41 UTC
+++ third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc
@@ -151,7 +151,7 @@ bool ScrollbarThemeAura::SupportsDragSnapBack() const 
 // is true for at least GTK and QT apps).
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return false;
 #else
   return true;
@@ -327,7 +327,7 @@ bool ScrollbarThemeAura::ShouldCenterOnThumb(const Scr
                                              const WebMouseEvent& event) {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   if (event.button == WebPointerProperties::Button::kMiddle)
     return true;
 #endif
