--- third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc.orig	2019-01-09 13:20:32.931933000 +0100
+++ third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc	2019-01-09 13:21:17.842418000 +0100
@@ -332,7 +332,7 @@
 
 bool ScrollbarThemeAura::ShouldCenterOnThumb(const Scrollbar& scrollbar,
                                              const WebMouseEvent& event) {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS))
   if (event.button == WebPointerProperties::Button::kMiddle)
     return true;
 #endif
