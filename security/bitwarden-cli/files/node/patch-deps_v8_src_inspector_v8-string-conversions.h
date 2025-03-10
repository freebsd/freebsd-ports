--- deps/v8/src/inspector/v8-string-conversions.h.orig	2024-08-21 12:35:26 UTC
+++ deps/v8/src/inspector/v8-string-conversions.h
@@ -5,14 +5,16 @@
 #ifndef V8_INSPECTOR_V8_STRING_CONVERSIONS_H_
 #define V8_INSPECTOR_V8_STRING_CONVERSIONS_H_
 
+#include <uchar.h>
+
 #include <cstdint>
 #include <string>
 
 // Conversion routines between UT8 and UTF16, used by string-16.{h,cc}. You may
 // want to use string-16.h directly rather than these.
 namespace v8_inspector {
-std::basic_string<uint16_t> UTF8ToUTF16(const char* stringStart, size_t length);
-std::string UTF16ToUTF8(const uint16_t* stringStart, size_t length);
+std::basic_string<char16_t> UTF8ToUTF16(const char* stringStart, size_t length);
+std::string UTF16ToUTF8(const char16_t* stringStart, size_t length);
 }  // namespace v8_inspector
 
 #endif  // V8_INSPECTOR_V8_STRING_CONVERSIONS_H_
