- workaround for https://github.com/OpenLightingProject/ola/issues/1982

--- include/ola/io/ByteString.h.orig	2025-11-04 00:31:22.940654000 -0800
+++ include/ola/io/ByteString.h	2025-11-04 00:31:40.486954000 -0800
@@ -23,7 +23,36 @@
 
 #include <stdint.h>
 #include <string>
+#include <cstring>
 
+namespace std {
+
+template<>
+struct char_traits<uint8_t> {
+  typedef uint8_t char_type;
+  typedef int int_type;
+  typedef std::streamoff off_type;
+  typedef std::streampos pos_type;
+  typedef std::mbstate_t state_type;
+
+  static void assign(char_type& r, const char_type& a) { r = a; }
+  static char_type* assign(char_type* p, size_t count, char_type a) { return static_cast<char_type*>(std::memset(p, a, count)); }
+  static bool eq(const char_type& a, const char_type& b) { return a == b; }
+  static bool lt(const char_type& a, const char_type& b) { return a < b; }
+  static char_type* move(char_type* dest, const char_type* src, size_t count) { return static_cast<char_type*>(std::memmove(dest, src, count)); }
+  static char_type* copy(char_type* dest, const char_type* src, size_t count) { return static_cast<char_type*>(std::memcpy(dest, src, count)); }
+  static int compare(const char_type* s1, const char_type* s2, size_t count) { return std::memcmp(s1, s2, count); }
+  static size_t length(const char_type* s) { return std::strlen(reinterpret_cast<const char*>(s)); }
+  static const char_type* find(const char_type* p, size_t count, const char_type& ch) { return static_cast<const char_type*>(std::memchr(p, ch, count)); }
+  static char_type to_char_type(const int_type& c) { return static_cast<char_type>(c); }
+  static int_type to_int_type(const char_type& c) { return static_cast<int_type>(c); }
+  static bool eq_int_type(const int_type& c1, const int_type& c2) { return c1 == c2; }
+  static int_type eof() { return static_cast<int_type>(EOF); }
+  static int_type not_eof(const int_type& c) { return (c == eof()) ? 0 : c; }
+};
+
+}  // namespace std
+
 namespace ola {
 namespace io {
 
