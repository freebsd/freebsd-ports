--- dlib/unicode/unicode.h.orig	2022-05-08 14:35:36 UTC
+++ dlib/unicode/unicode.h
@@ -16,7 +16,7 @@ namespace dlib
 
 // ----------------------------------------------------------------------------------------
 
-    typedef uint32 unichar;
+    typedef char32_t unichar;
 
 #if defined(__GNUC__) && __GNUC__ < 4 && __GNUC_MINOR__ < 4
     struct unichar_traits 
