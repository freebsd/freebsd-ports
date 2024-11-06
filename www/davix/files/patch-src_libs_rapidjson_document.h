--- src/libs/rapidjson/document.h.orig	2024-06-24 15:50:44 UTC
+++ src/libs/rapidjson/document.h
@@ -316,8 +316,6 @@ struct GenericStringRef {
 
     GenericStringRef(const GenericStringRef& rhs) : s(rhs.s), length(rhs.length) {}
 
-    GenericStringRef& operator=(const GenericStringRef& rhs) { s = rhs.s; length = rhs.length; }
-
     //! implicit conversion to plain CharType pointer
     operator const Ch *() const { return s; }
 
