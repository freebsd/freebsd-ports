--- talk/base/stringutils.h.orig	2008-09-06 23:10:21.000000000 -0300
+++ talk/base/stringutils.h	2008-09-06 23:13:17.000000000 -0300
@@ -197,15 +197,6 @@
 }
 
 template<class CTYPE>
-size_t sprintfn(CTYPE* buffer, size_t buflen, const CTYPE* format, ...) {
-  va_list args;
-  va_start(args, format);
-  size_t len = vsprintfn(buffer, buflen, format, args);
-  va_end(args);
-  return len;
-}
-
-template<class CTYPE>
 size_t vsprintfn(CTYPE* buffer, size_t buflen, const CTYPE* format,
                  va_list args) {
   int len = vsnprintf(buffer, buflen, format, args);
@@ -216,6 +207,15 @@
   return len;
 }
 
+template<class CTYPE>
+size_t sprintfn(CTYPE* buffer, size_t buflen, const CTYPE* format, ...) {
+  va_list args;
+  va_start(args, format);
+  size_t len = vsprintfn(buffer, buflen, format, args);
+  va_end(args);
+  return len;
+}
+
 ///////////////////////////////////////////////////////////////////////////////
 // Allow safe comparing and copying ascii (not UTF-8) with both wide and
 // non-wide character strings.
@@ -269,7 +269,7 @@
 template<>
 struct Traits<char> {
   typedef std::string string;
-  inline static const char* Traits<char>::empty_str() { return ""; }
+  inline static const char* empty_str() { return ""; } 
 };
 
 ///////////////////////////////////////////////////////////////////////////////
