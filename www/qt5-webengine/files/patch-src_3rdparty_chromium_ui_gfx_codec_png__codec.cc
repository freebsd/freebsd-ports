--- src/3rdparty/chromium/ui/gfx/codec/png_codec.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/ui/gfx/codec/png_codec.cc
@@ -169,6 +169,10 @@ void DecodeInfoCallback(png_struct* png_ptr, png_info*
         png_set_bgr(png_ptr);
         png_set_add_alpha(png_ptr, 0xFF, PNG_FILLER_AFTER);
         break;
+      case PNGCodec::FORMAT_ARGB:
+        state->output_channels = 4;
+        png_set_add_alpha(png_ptr, 0xFF, PNG_FILLER_BEFORE);
+        break;
       case PNGCodec::FORMAT_SkBitmap:
         state->output_channels = 4;
         png_set_add_alpha(png_ptr, 0xFF, PNG_FILLER_AFTER);
@@ -183,6 +187,10 @@ void DecodeInfoCallback(png_struct* png_ptr, png_info*
         state->output_channels = 4;
         png_set_bgr(png_ptr);
         break;
+      case PNGCodec::FORMAT_ARGB:
+        state->output_channels = 4;
+	png_set_swap_alpha(png_ptr);
+        break;
       case PNGCodec::FORMAT_SkBitmap:
         state->output_channels = 4;
         break;
@@ -475,6 +483,8 @@ bool PNGCodec::Encode(const unsigned char* input,
     case FORMAT_BGRA:
       colorType = kBGRA_8888_SkColorType;
       break;
+    case FORMAT_ARGB:
+      return false;
     case FORMAT_SkBitmap:
       colorType = kN32_SkColorType;
       break;
