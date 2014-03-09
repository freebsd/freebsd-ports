--- ../x10.runtime/src-cpp/x10aux/string_utils.h.orig	2014-03-09 14:42:24.000000000 +0100
+++ ../x10.runtime/src-cpp/x10aux/string_utils.h	2014-03-09 14:45:00.000000000 +0100
@@ -38,23 +38,6 @@
         char *strdup(const char*);
         char *strndup(const char*, x10_int len);
     }
-
-    /*
-     * Wrapers around to_string to translate null to "null"
-     */
-    template<class T> ref<x10::lang::String> safe_to_string(ref<T> v) {
-        if (v.isNull()) return string_utils::lit("null");
-        return to_string(v);
-    }
-    template<class T> ref<x10::lang::String> safe_to_string(captured_ref_lval<T> v) {
-        return safe_to_string(*v);
-    }
-    template<class T> ref<x10::lang::String> safe_to_string(captured_struct_lval<T> v) {
-        return to_string(*v);
-    }
-    template<class T> ref<x10::lang::String> safe_to_string(T v) {
-        return to_string(v);
-    }
 }
 
     

