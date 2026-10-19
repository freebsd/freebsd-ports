--- third_party/blink/renderer/platform/fonts/web_font_decoder.cc.orig	2026-10-18 13:29:39 UTC
+++ third_party/blink/renderer/platform/fonts/web_font_decoder.cc
@@ -33,27 +33,19 @@
 #include <hb.h>
 #include <stdarg.h>
 
-#include <string>
-
 #include "base/compiler_specific.h"
-#include "base/containers/span.h"
-#include "base/numerics/byte_conversions.h"
 #include "base/numerics/safe_conversions.h"
 #include "build/build_config.h"
 #include "third_party/blink/public/platform/platform.h"
 #include "third_party/blink/renderer/platform/fonts/font_cache.h"
-#include "third_party/blink/renderer/platform/fonts/ift/ift_patcher.h"
 #include "third_party/blink/renderer/platform/fonts/web_font_typeface_factory.h"
 #include "third_party/blink/renderer/platform/instrumentation/tracing/trace_event.h"
-#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
 #include "third_party/blink/renderer/platform/wtf/shared_buffer.h"
 #include "third_party/blink/renderer/platform/wtf/text/format.h"
 #include "third_party/blink/renderer/platform/wtf/text/string_builder.h"
 #include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
 #include "third_party/ots/src/include/ots-memory-stream.h"
 #include "third_party/skia/include/core/SkStream.h"
-#include "third_party/woff2/include/woff2/decode.h"
-#include "third_party/woff2/include/woff2/output.h"
 
 namespace blink {
 
@@ -65,11 +57,6 @@ const size_t kMaxDecompressedSizeMb = 30;
 const size_t kMaxDecompressedSizeMb = 128;
 #endif
 
-constexpr size_t kMaxDecompressedSize = kMaxDecompressedSizeMb * 1024 * 1024;
-
-constexpr uint32_t kWoffTag = OTS_TAG('w', 'O', 'F', 'F');
-constexpr uint32_t kWoff2Tag = OTS_TAG('w', 'O', 'F', '2');
-
 class BlinkOTSContext final : public ots::OTSContext {
   DISALLOW_NEW();
 
@@ -189,94 +176,17 @@ ots::TableAction BlinkOTSContext::GetTableAction(uint3
   }
 }
 
-struct FontDecodeResult {
-  std::unique_ptr<IftPatcher> ift_patcher;
-};
-
-// Decompresses and sanitizes `font_data` into an output stream using
-// `ots_context`, and initializes `ift_patcher` if `font_data` is an IFT-enabled
-// font. Returns whether decoding succeeded. On failure, the error string can be
-// retrieved from `ots_context`.
-bool DecodeFontWithIft(BlinkOTSContext& ots_context,
-                       base::span<const uint8_t> font_data,
-                       ots::ExpandingMemoryStream* output,
-                       std::unique_ptr<IftPatcher>& ift_patcher) {
-  TRACE_EVENT("blink", "DecodeFont");
-
-  uint32_t magic = 0;
-  if (font_data.size() >= 4) {
-    magic = base::U32FromBigEndian(font_data.first<4u>());
-  }
-
-  switch (magic) {
-    case kWoff2Tag: {
-      size_t decompressed_size =
-          woff2::ComputeWOFF2FinalSize(font_data.data(), font_data.size());
-      if (decompressed_size == 0) {
-        ots_context.Message(0, "Size of decompressed WOFF 2.0 is set to 0");
-        return false;
-      }
-      if (decompressed_size < font_data.size()) {
-        ots_context.Message(
-            0, "Size of decompressed WOFF 2.0 is less than compressed size");
-        return false;
-      }
-      if (decompressed_size > kMaxDecompressedSize) {
-        ots_context.Message(0,
-                            "Size of decompressed WOFF 2.0 font exceeds %gMB",
-                            kMaxDecompressedSize / (1024.0 * 1024.0));
-        return false;
-      }
-
-      std::string buf(decompressed_size, 0);
-      woff2::WOFF2StringOut out(&buf);
-      if (!woff2::ConvertWOFF2ToTTF(font_data.data(), font_data.size(), &out)) {
-        ots_context.Message(0, "Failed to convert WOFF 2.0 font to SFNT");
-        return false;
-      }
-
-      base::span<const uint8_t> decompressed_span =
-          base::as_byte_span(buf).first(out.Size());
-      if (!ots_context.Process(output, decompressed_span.data(),
-                               decompressed_span.size())) {
-        return false;
-      }
-      ift_patcher = IftPatcher::Create(decompressed_span);
-      break;
-    }
-    case kWoffTag: {
-      // The IFT (Incremental Font Transfer) specification recommends using
-      // WOFF2. OTS handles WOFF decompression directly, so we do not extract
-      // unsanitized font data or create an IftPatcher for the WOFF format.
-      if (!ots_context.Process(output, font_data.data(), font_data.size())) {
-        return false;
-      }
-      break;
-    }
-    default: {
-      if (!ots_context.Process(output, font_data.data(), font_data.size())) {
-        return false;
-      }
-      ift_patcher = IftPatcher::Create(font_data);
-      break;
-    }
-  }
-
-  return true;
-}
-
 }  // namespace
 
-DecodedWebFont::DecodedWebFont() = default;
-DecodedWebFont::DecodedWebFont(DecodedWebFont&&) noexcept = default;
-DecodedWebFont& DecodedWebFont::operator=(DecodedWebFont&&) noexcept = default;
-DecodedWebFont::~DecodedWebFont() = default;
-
-base::expected<DecodedWebFont, String> DecodeWebFont(SegmentedBuffer* buffer) {
+base::expected<DecodedWebFont, String> DecodedWebFont::Create(
+    SegmentedBuffer* buffer) {
   if (!buffer) {
     return base::unexpected("Empty Buffer");
   }
 
+  // This is the largest web font size which we'll try to transcode.
+  static const size_t kMaxDecompressedSize =
+      kMaxDecompressedSizeMb * 1024 * 1024;
   if (buffer->size() > kMaxDecompressedSize) {
     return base::unexpected(
         Format("Web font size more than {}MB", kMaxDecompressedSizeMb));
@@ -291,11 +201,7 @@ base::expected<DecodedWebFont, String> DecodeWebFont(S
   SegmentedBuffer::DeprecatedFlatData flattened_buffer(buffer);
 
   bool ok;
-  std::unique_ptr<IftPatcher> ift_patcher;
-  if (RuntimeEnabledFeatures::IncrementalFontTransferEnabled()) {
-    ok = DecodeFontWithIft(ots_context, base::as_byte_span(flattened_buffer),
-                           output.get(), ift_patcher);
-  } else {
+  {
     TRACE_EVENT("blink", "DecodeFont");
     ok = ots_context.Process(
         output.get(), reinterpret_cast<const uint8_t*>(flattened_buffer.data()),
@@ -307,9 +213,9 @@ base::expected<DecodedWebFont, String> DecodeWebFont(S
   }
 
   const void* decoded_data = output->get();
-  DecodedWebFont result;
-  result.ift_patcher = std::move(ift_patcher);
-  result.decoded_size = base::checked_cast<size_t>(output->Tell());
+  DecodedWebFont result{
+      .decoded_size = base::checked_cast<size_t>(output->Tell()),
+  };
   sk_sp<SkData> sk_data = SkData::MakeWithProc(
       decoded_data, result.decoded_size,
       [](const void*, void* output) {
