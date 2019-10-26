--- src/3rdparty/chromium/third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc
@@ -332,7 +332,7 @@ ScrollbarPart ScrollbarThemeAura::InvalidateOnThumbPos
 
 bool ScrollbarThemeAura::ShouldCenterOnThumb(const Scrollbar& scrollbar,
                                              const WebMouseEvent& event) {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS))
   if (event.button == WebPointerProperties::Button::kMiddle)
     return true;
 #endif
