--- deps/v8/src/inspector/string-16.h.orig	2024-08-21 12:35:26 UTC
+++ deps/v8/src/inspector/string-16.h
@@ -6,6 +6,7 @@
 #define V8_INSPECTOR_STRING_16_H_
 
 #include <stdint.h>
+#include <uchar.h>
 
 #include <cctype>
 #include <climits>
@@ -17,7 +18,7 @@ namespace v8_inspector {
 
 namespace v8_inspector {
 
-using UChar = uint16_t;
+using UChar = char16_t;
 
 class String16 {
  public:
@@ -27,6 +28,7 @@ class String16 {
   String16(const String16&) V8_NOEXCEPT = default;
   String16(String16&&) V8_NOEXCEPT = default;
   String16(const UChar* characters, size_t size);
+  String16(const uint16_t* characters, size_t size);
   V8_EXPORT String16(const UChar* characters);
   V8_EXPORT String16(const char* characters);
   String16(const char* characters, size_t size);
@@ -48,7 +50,9 @@ class String16 {
   int toInteger(bool* ok = nullptr) const;
   std::pair<size_t, size_t> getTrimmedOffsetAndLength() const;
   String16 stripWhiteSpace() const;
-  const UChar* characters16() const { return m_impl.c_str(); }
+  const uint16_t* characters16() const {
+    return reinterpret_cast<const uint16_t*>(m_impl.c_str());
+  }
   size_t length() const { return m_impl.length(); }
   bool isEmpty() const { return !m_impl.length(); }
   UChar operator[](size_t index) const { return m_impl[index]; }
@@ -77,6 +81,8 @@ class String16 {
   // Instantiates a String16 in native endianness from UTF16 LE.
   // On Big endian architectures, byte order needs to be flipped.
   V8_EXPORT static String16 fromUTF16LE(const UChar* stringStart,
+                                        size_t length);
+  V8_EXPORT static String16 fromUTF16LE(const uint16_t* stringStart,
                                         size_t length);
 
   std::size_t hash() const {
