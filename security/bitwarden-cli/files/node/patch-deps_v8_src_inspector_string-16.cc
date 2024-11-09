--- deps/v8/src/inspector/string-16.cc.orig	2024-08-21 12:35:26 UTC
+++ deps/v8/src/inspector/string-16.cc
@@ -27,7 +27,7 @@ bool isSpaceOrNewLine(UChar c) {
   return isASCII(c) && c <= ' ' && (c == ' ' || (c <= 0xD && c >= 0x9));
 }
 
-int64_t charactersToInteger(const UChar* characters, size_t length,
+int64_t charactersToInteger(const uint16_t* characters, size_t length,
                             bool* ok = nullptr) {
   std::vector<char> buffer;
   buffer.reserve(length + 1);
@@ -50,6 +50,8 @@ String16::String16(const UChar* characters, size_t siz
 
 String16::String16(const UChar* characters, size_t size)
     : m_impl(characters, size) {}
+String16::String16(const uint16_t* characters, size_t size)
+    : m_impl(reinterpret_cast<const UChar*>(characters), size) {}
 
 String16::String16(const UChar* characters) : m_impl(characters) {}
 
@@ -239,6 +241,10 @@ String16 String16::fromUTF16LE(const UChar* stringStar
   // No need to do anything on little endian machines.
   return String16(stringStart, length);
 #endif  // V8_TARGET_BIG_ENDIAN
+}
+
+String16 String16::fromUTF16LE(const uint16_t* stringStart, size_t length) {
+  return fromUTF16LE(reinterpret_cast<const UChar*>(stringStart), length);
 }
 
 std::string String16::utf8() const {
