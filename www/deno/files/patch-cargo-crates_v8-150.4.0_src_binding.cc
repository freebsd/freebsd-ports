--- cargo-crates/v8-150.4.0/src/binding.cc.orig	2026-09-17 22:38:34 UTC
+++ cargo-crates/v8-150.4.0/src/binding.cc
@@ -4667,6 +4667,19 @@ size_t simdutf__convert_utf16be_to_utf8(const char16_t
   return simdutf::convert_utf16be_to_utf8(input, length, output);
 }
 
+simdutf__result simdutf__convert_utf8_to_utf16be_with_errors(const char* input,
+                                                             size_t length,
+                                                             char16_t* output) {
+  return to_ffi_result(
+      simdutf::convert_utf8_to_utf16be_with_errors(input, length, output));
+}
+
+simdutf__result simdutf__convert_utf16be_to_utf8_with_errors(
+    const char16_t* input, size_t length, char* output) {
+  return to_ffi_result(
+      simdutf::convert_utf16be_to_utf8_with_errors(input, length, output));
+}
+
 // --- Conversion: UTF-8 <-> Latin-1 ---
 
 size_t simdutf__convert_utf8_to_latin1(const char* input, size_t length,
