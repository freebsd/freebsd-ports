--- dlib/serialize.h.orig	2024-02-17 21:44:22 UTC
+++ dlib/serialize.h
@@ -639,6 +639,8 @@ namespace dlib
     USE_DEFAULT_INT_SERIALIZATION_FOR(wchar_t)
 #endif
 
+    USE_DEFAULT_INT_SERIALIZATION_FOR(char32_t)
+
 // ----------------------------------------------------------------------------------------
 
     inline void serialize(
