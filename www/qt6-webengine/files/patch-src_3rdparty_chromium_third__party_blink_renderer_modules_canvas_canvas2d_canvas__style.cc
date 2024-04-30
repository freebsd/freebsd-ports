--- src/3rdparty/chromium/third_party/blink/renderer/modules/canvas/canvas2d/canvas_style.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/modules/canvas/canvas2d/canvas_style.cc
@@ -76,6 +76,9 @@ void CanvasStyle::ApplyToFlags(cc::PaintFlags& flags,
 
 void CanvasStyle::ApplyToFlags(cc::PaintFlags& flags,
                                float global_alpha) const {
+#if defined(__clang__) && (__clang_major__ < 16)
+  SkColor4f custom_color = SkColor4f{0.0f, 0.0f, 0.0f, global_alpha};
+#endif
   switch (type_) {
     case kColor:
       ApplyColorToFlags(flags, global_alpha);
