- https://github.com/automl/random_forest_run/issues/8

--- include/cereal/external/rapidjson/document.h.orig	2025-06-29 20:57:03 UTC
+++ include/cereal/external/rapidjson/document.h
@@ -322,7 +322,7 @@ struct GenericStringRef {
     operator const Ch *() const { return s; }
 
     const Ch* const s; //!< plain CharType pointer
-    const SizeType length; //!< length of the string (excluding the trailing NULL terminator)
+    SizeType length; //!< length of the string (excluding the trailing NULL terminator)
 
 private:
     //! Disallow construction from non-const array
