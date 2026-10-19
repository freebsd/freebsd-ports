--- third_party/blink/renderer/core/loader/resource/font_resource.cc.orig	2026-10-18 13:29:39 UTC
+++ third_party/blink/renderer/core/loader/resource/font_resource.cc
@@ -44,7 +44,6 @@
 #include "third_party/blink/public/mojom/loader/request_context_frame_type.mojom-blink.h"
 #include "third_party/blink/renderer/platform/fonts/font_custom_platform_data.h"
 #include "third_party/blink/renderer/platform/fonts/font_platform_data.h"
-#include "third_party/blink/renderer/platform/fonts/ift/ift_patcher.h"
 #include "third_party/blink/renderer/platform/fonts/web_font_decoder.h"
 #include "third_party/blink/renderer/platform/heap/cross_thread_handle.h"
 #include "third_party/blink/renderer/platform/loader/fetch/fetch_parameters.h"
@@ -85,7 +84,8 @@ base::expected<DecodedWebFont, String> DecodeFont(Segm
     return base::unexpected("");
   }
   auto decode_start_time = base::TimeTicks::Now();
-  base::expected<DecodedWebFont, String> result = DecodeWebFont(buffer);
+  base::expected<DecodedWebFont, String> result =
+      DecodedWebFont::Create(buffer);
   base::UmaHistogramMicrosecondsTimes(
       "Blink.Fonts.BackgroundDecodeTime",
       base::TimeTicks::Now() - decode_start_time);
@@ -316,22 +316,13 @@ const FontCustomPlatformData* FontResource::GetCustomF
         font_data_ = FontCustomPlatformData::Create(
             std::move(background_decode_result_->sk_typeface),
             background_decode_result_->decoded_size);
-        ift_patcher_ = std::move(background_decode_result_->ift_patcher);
       } else {
         auto decode_start_time = base::TimeTicks::Now();
-        base::expected<DecodedWebFont, String> decode_result =
-            DecodeWebFont(Data());
+	font_data_ =
+            FontCustomPlatformData::Create(Data(), ots_parsing_message_);
         base::UmaHistogramMicrosecondsTimes(
             "Blink.Fonts.DecodeTime",
             base::TimeTicks::Now() - decode_start_time);
-        if (decode_result.has_value()) {
-          font_data_ = FontCustomPlatformData::Create(
-              std::move(decode_result->sk_typeface),
-              decode_result->decoded_size);
-          ift_patcher_ = std::move(decode_result->ift_patcher);
-        } else {
-          ots_parsing_message_ = std::move(decode_result).error();
-        }
       }
     } else {
       ots_parsing_message_ = background_decode_result_.error();
@@ -340,7 +331,6 @@ const FontCustomPlatformData* FontResource::GetCustomF
 
   if (!font_data_) {
     SetStatus(ResourceStatus::kDecodeError);
-    ift_patcher_.reset();
   } else {
     // Call observers once and remove them.
     HeapHashSet<WeakMember<FontResourceClearDataObserver>> observers;
@@ -351,10 +341,6 @@ const FontCustomPlatformData* FontResource::GetCustomF
     ClearData();
   }
   return font_data_;
-}
-
-std::unique_ptr<IftPatcher> FontResource::TakeIftPatcher() {
-  return std::move(ift_patcher_);
 }
 
 void FontResource::WillReloadAfterDiskCacheMiss() {
