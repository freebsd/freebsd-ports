--- third_party/blink/renderer/modules/canvas/canvas2d/canvas_style.cc.orig	2023-12-23 12:33:28 UTC
+++ third_party/blink/renderer/modules/canvas/canvas2d/canvas_style.cc
@@ -83,6 +83,9 @@ bool ParseCanvasColorString(const String& color_string
 
 void CanvasStyle::ApplyToFlags(cc::PaintFlags& flags,
                                float global_alpha) const {
+#if defined(__clang__) && (__clang_major__ < 16)
+  SkColor4f custom_color = SkColor4f{0.0f, 0.0f, 0.0f, global_alpha};
+#endif
   switch (type_) {
     case kColor:
       ApplyColorToFlags(flags, global_alpha);
@@ -90,12 +93,20 @@ void CanvasStyle::ApplyToFlags(cc::PaintFlags& flags,
     case kGradient:
       GetCanvasGradient()->GetGradient()->ApplyToFlags(flags, SkMatrix::I(),
                                                        ImageDrawOptions());
+#if defined(__clang__) && (__clang_major__ >= 16)
       flags.setColor(SkColor4f(0.0f, 0.0f, 0.0f, global_alpha));
+#else
+      flags.setColor(custom_color);
+#endif
       break;
     case kImagePattern:
       GetCanvasPattern()->GetPattern()->ApplyToFlags(
           flags, AffineTransformToSkMatrix(GetCanvasPattern()->GetTransform()));
+#if defined(__clang__) && (__clang_major__ >= 16)
       flags.setColor(SkColor4f(0.0f, 0.0f, 0.0f, global_alpha));
+#else
+      flags.setColor(custom_color);
+#endif
       break;
     default:
       NOTREACHED();
