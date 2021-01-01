--- third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc.orig	2020-03-16 18:39:56 UTC
+++ third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc
@@ -137,7 +137,7 @@ bool ScrollbarThemeAura::SupportsDragSnapBack() const 
 // Disable snapback on desktop Linux to better integrate with the desktop
 // behavior. Typically, Linux apps do not implement scrollbar snapback (this
 // is true for at least GTK and QT apps).
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return false;
 #endif
 
@@ -301,7 +301,7 @@ ScrollbarPart ScrollbarThemeAura::PartsToInvalidateOnT
 
 bool ScrollbarThemeAura::ShouldCenterOnThumb(const Scrollbar& scrollbar,
                                              const WebMouseEvent& event) {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS))
   if (event.button == WebPointerProperties::Button::kMiddle)
     return true;
 #endif
