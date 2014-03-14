--- ../x10.runtime/src-cpp/x10aux/basic_functions.h.orig	2014-03-09 14:42:17.000000000 +0100
+++ ../x10.runtime/src-cpp/x10aux/basic_functions.h	2014-03-09 15:44:47.000000000 +0100
@@ -31,6 +31,27 @@
 
 namespace x10aux {
 
+    /* prototypes */
+    inline x10_boolean struct_equals(const x10_double x,  const x10_double y); 
+    inline x10_boolean struct_equals(const x10_float x,   const x10_float y);
+    inline x10_boolean struct_equals(const x10_long x,    const x10_long y);
+    inline x10_boolean struct_equals(const x10_int x,     const x10_int y);
+    inline x10_boolean struct_equals(const x10_short x,   const x10_short y);
+    inline x10_boolean struct_equals(const x10_byte x,    const x10_byte y);
+    inline x10_boolean struct_equals(const x10_ulong x,   const x10_ulong y);
+    inline x10_boolean struct_equals(const x10_uint x,    const x10_uint y);
+    inline x10_boolean struct_equals(const x10_ushort x,  const x10_ushort y);
+    inline x10_boolean struct_equals(const x10_ubyte x,   const x10_ubyte y);
+    inline x10_boolean struct_equals(const x10_char x,    const x10_char y);
+    inline x10_boolean struct_equals(const x10_boolean x, const x10_boolean y);
+    template<class T, class U> inline x10_boolean struct_equals(T x, U y);
+    template<class T, class U> inline x10_boolean struct_equals(captured_ref_lval<T> x, U y);
+    template<class T, class U> inline x10_boolean struct_equals(T x, captured_ref_lval<U> y);
+    template<class T, class U> inline x10_boolean struct_equals(captured_ref_lval<T> x, captured_ref_lval<U> y);
+    template<class T, class U> inline x10_boolean struct_equals(captured_struct_lval<T> x, U y);
+    template<class T, class U> inline x10_boolean struct_equals(T x, captured_struct_lval<U> y);
+    template<class T, class U> inline x10_boolean struct_equals(captured_struct_lval<T> x, captured_struct_lval<U> y);
+
     /******* type_name ********/
 
     template<class T> inline ref<x10::lang::String> type_name(ref<T> x) {
@@ -362,6 +383,23 @@
 
     ref<x10::lang::String> to_string(x10_char v);
 
+    /*
+     * Wrapers around to_string to translate null to "null"
+     */
+    template<class T> ref<x10::lang::String> safe_to_string(ref<T> v) {
+        if (v.isNull()) return string_utils::lit("null");
+        return to_string(v);
+    }
+    template<class T> ref<x10::lang::String> safe_to_string(captured_ref_lval<T> v) {
+        return safe_to_string(*v);
+    }
+    template<class T> ref<x10::lang::String> safe_to_string(captured_struct_lval<T> v) {
+        return to_string(*v);
+    }
+    template<class T> ref<x10::lang::String> safe_to_string(T v) {
+        return to_string(v);
+    }
+
 
     /******* zeroValue ********/
     template<class T> struct Zero {
