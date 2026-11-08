--- third_party/blink/renderer/platform/fonts/opentype/font_format_check.cc.orig	2026-09-25 15:26:43 UTC
+++ third_party/blink/renderer/platform/fonts/opentype/font_format_check.cc
@@ -7,6 +7,7 @@
 #include "base/containers/span.h"
 #include "base/containers/span_rust.h"
 #include "base/numerics/byte_conversions.h"
+#include "third_party/blink/renderer/platform/fonts/opentype/format_check.rs.h"
 #include "third_party/blink/renderer/platform/runtime_enabled_features.h"
 #include "third_party/blink/renderer/platform/wtf/vector.h"
 #include "third_party/skia/include/core/SkTypeface.h"
@@ -14,37 +15,35 @@
 namespace blink {
 
 FontFormatCheck::FontFormatCheck(sk_sp<SkData> sk_data)
-    : format_info_(font_format::get_font_format_info(
+    : format_info_(font_format_check::get_font_format_info(
           base::SpanToRustSlice(sk_data->byteSpan()))) {}
 
-FontFormatCheck::~FontFormatCheck() = default;
-
 bool FontFormatCheck::IsVariableFont() const {
-  return font_format::is_variable(format_info_);
+  return font_format_check::is_variable(*format_info_);
 }
 
 bool FontFormatCheck::IsCbdtCblcColorFont() const {
-  return font_format::is_cbdt_cblc(format_info_);
+  return font_format_check::is_cbdt_cblc(*format_info_);
 }
 
 bool FontFormatCheck::IsEbdtEblcMonochromeFont() const {
-  return font_format::is_ebdt_eblc(format_info_);
+  return font_format_check::is_ebdt_eblc(*format_info_);
 }
 
 bool FontFormatCheck::IsColrCpalColorFontV0() const {
-  return font_format::is_colrv0(format_info_);
+  return font_format_check::is_colrv0(*format_info_);
 }
 
 bool FontFormatCheck::IsColrCpalColorFontV1() const {
-  return font_format::is_colrv1(format_info_);
+  return font_format_check::is_colrv1(*format_info_);
 }
 
 bool FontFormatCheck::IsSbixColorFont() const {
-  return font_format::is_sbix(format_info_);
+  return font_format_check::is_sbix(*format_info_);
 }
 
 bool FontFormatCheck::IsCff2OutlineFont() const {
-  return font_format::is_cff2(format_info_);
+  return font_format_check::is_cff2(*format_info_);
 }
 
 bool FontFormatCheck::IsVariableColrV0Font() const {
@@ -58,7 +57,7 @@ bool FontFormatCheck::IsColorFont() const {
 
 bool FontFormatCheck::IsAvar2Font() const {
   return RuntimeEnabledFeatures::FontFormatAvar2Enabled() &&
-         font_format::is_avar2(format_info_);
+         font_format_check::is_avar2(*format_info_);
 }
 
 FontFormatCheck::VariableFontSubType FontFormatCheck::ProbeVariableFont(
