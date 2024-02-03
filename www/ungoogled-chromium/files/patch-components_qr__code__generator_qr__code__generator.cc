--- components/qr_code_generator/qr_code_generator.cc.orig	2024-02-03 15:42:55 UTC
+++ components/qr_code_generator/qr_code_generator.cc
@@ -11,12 +11,16 @@
 #include <vector>
 
 #include "base/check_op.h"
+#ifdef notyet
 #include "base/containers/span_rust.h"
+#endif
 #include "base/memory/raw_ptr.h"
 #include "base/notreached.h"
 #include "base/numerics/safe_conversions.h"
 #include "components/qr_code_generator/features.h"
+#ifdef notyet
 #include "components/qr_code_generator/qr_code_generator_ffi_glue.rs.h"
+#endif
 
 namespace qr_code_generator {
 
@@ -572,6 +576,7 @@ size_t SegmentSpanLength(base::span<const QRCodeGenera
   return sum;
 }
 
+#ifdef notyet
 absl::optional<QRCodeGenerator::GeneratedCode> GenerateQrCodeUsingRust(
     base::span<const uint8_t> in,
     absl::optional<int> min_version) {
@@ -596,6 +601,7 @@ absl::optional<QRCodeGenerator::GeneratedCode> Generat
   CHECK_EQ(code.data.size(), static_cast<size_t>(code.qr_size * code.qr_size));
   return code;
 }
+#endif
 
 }  // namespace
 
@@ -617,9 +623,11 @@ absl::optional<QRCodeGenerator::GeneratedCode> QRCodeG
     return absl::nullopt;
   }
 
+#ifdef notyet
   if (IsRustyQrCodeGeneratorFeatureEnabled()) {
     return GenerateQrCodeUsingRust(in, min_version);
   }
+#endif
 
   std::vector<Segment> segments;
   const QRVersionInfo* version_info = nullptr;
