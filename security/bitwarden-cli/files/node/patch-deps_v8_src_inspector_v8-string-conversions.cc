--- deps/v8/src/inspector/v8-string-conversions.cc.orig	2024-08-21 12:35:26 UTC
+++ deps/v8/src/inspector/v8-string-conversions.cc
@@ -12,7 +12,7 @@ namespace {
 
 namespace v8_inspector {
 namespace {
-using UChar = uint16_t;
+using UChar = char16_t;
 using UChar32 = uint32_t;
 
 bool isASCII(UChar c) { return !(c & ~0x7F); }
@@ -386,7 +386,7 @@ std::basic_string<UChar> UTF8ToUTF16(const char* strin
 
 std::basic_string<UChar> UTF8ToUTF16(const char* stringStart, size_t length) {
   if (!stringStart || !length) return std::basic_string<UChar>();
-  std::vector<uint16_t> buffer(length);
+  std::vector<UChar> buffer(length);
   UChar* bufferStart = buffer.data();
 
   UChar* bufferCurrent = bufferStart;
@@ -395,7 +395,7 @@ std::basic_string<UChar> UTF8ToUTF16(const char* strin
                          reinterpret_cast<const char*>(stringStart + length),
                          &bufferCurrent, bufferCurrent + buffer.size(), nullptr,
                          true) != conversionOK)
-    return std::basic_string<uint16_t>();
+    return std::basic_string<UChar>();
   size_t utf16Length = bufferCurrent - bufferStart;
   return std::basic_string<UChar>(bufferStart, bufferStart + utf16Length);
 }
