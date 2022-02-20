--- third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc.orig	2022-02-07 13:39:41 UTC
+++ third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc
@@ -152,7 +152,7 @@ bool ScrollbarThemeAura::SupportsDragSnapBack() const 
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
