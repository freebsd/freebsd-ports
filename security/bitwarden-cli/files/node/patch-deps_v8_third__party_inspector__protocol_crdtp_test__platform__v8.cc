--- deps/v8/third_party/inspector_protocol/crdtp/test_platform_v8.cc.orig	2024-08-21 12:35:28 UTC
+++ deps/v8/third_party/inspector_protocol/crdtp/test_platform_v8.cc
@@ -11,13 +11,16 @@ std::string UTF16ToUTF8(span<uint16_t> in) {
 namespace v8_crdtp {
 
 std::string UTF16ToUTF8(span<uint16_t> in) {
-  return v8_inspector::UTF16ToUTF8(in.data(), in.size());
+  return v8_inspector::UTF16ToUTF8(reinterpret_cast<const char16_t*>(in.data()),
+                                   in.size());
 }
 
 std::vector<uint16_t> UTF8ToUTF16(span<uint8_t> in) {
-  std::basic_string<uint16_t> utf16 = v8_inspector::UTF8ToUTF16(
+  std::basic_string<char16_t> utf16 = v8_inspector::UTF8ToUTF16(
       reinterpret_cast<const char*>(in.data()), in.size());
-  return std::vector<uint16_t>(utf16.begin(), utf16.end());
+  return std::vector<uint16_t>(
+      reinterpret_cast<const uint16_t*>(utf16.data()),
+      reinterpret_cast<const uint16_t*>(utf16.data()) + utf16.size());
 }
 
 }  // namespace v8_crdtp
