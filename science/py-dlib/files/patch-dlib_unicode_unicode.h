--- dlib/unicode/unicode.h.orig	2024-02-17 21:44:22 UTC
+++ dlib/unicode/unicode.h
@@ -16,7 +16,7 @@ namespace dlib
 
 // ----------------------------------------------------------------------------------------
 
-    using unichar = uint32;
+    using unichar = char32_t;
     using ustring = std::basic_string<unichar>;
 
 // ----------------------------------------------------------------------------------------
