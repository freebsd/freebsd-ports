--- third_party/blink/renderer/modules/canvas/canvas2d/canvas_style.cc.orig	2023-07-21 09:49:17 UTC
+++ third_party/blink/renderer/modules/canvas/canvas2d/canvas_style.cc
@@ -91,12 +91,20 @@ void CanvasStyle::ApplyToFlags(cc::PaintFlags& flags,
     case kGradient:
       GetCanvasGradient()->GetGradient()->ApplyToFlags(flags, SkMatrix::I(),
                                                        ImageDrawOptions());
+#if defined(__clang__) && (__clang_major__ >= 16)
       flags.setColor(SkColor4f(0.0f, 0.0f, 0.0f, global_alpha));
+#else
+      flags.setColor(SkColor4f({0.0f, 0.0f, 0.0f, global_alpha}));
+#endif
       break;
     case kImagePattern:
       GetCanvasPattern()->GetPattern()->ApplyToFlags(
           flags, AffineTransformToSkMatrix(GetCanvasPattern()->GetTransform()));
+#if defined(__clang__) && (__clang_major__ >= 16)
       flags.setColor(SkColor4f(0.0f, 0.0f, 0.0f, global_alpha));
+#else
+      flags.setColor(SkColor4f({0.0f, 0.0f, 0.0f, global_alpha}));
+#endif
       break;
     default:
       NOTREACHED();
