--- third_party/tensorpipe/third_party/libnop/include/nop/types/variant.h.orig	2020-07-24 02:13:02 UTC
+++ third_party/tensorpipe/third_party/libnop/include/nop/types/variant.h
@@ -238,7 +238,7 @@ class Variant {
   // resulting type.
   template <typename... Args>
   void Construct(Args&&... args) {
-    index_ = value_.template Construct(std::forward<Args>(args)...);
+    index_ = value_.template Construct<>(std::forward<Args>(args)...);
   }
   void Construct(EmptyVariant) {}
 
@@ -255,14 +255,14 @@ class Variant {
   // multiple element types.
   template <typename T, typename U>
   void Assign(TypeTag<T>, U&& value) {
-    if (!value_.template Assign(TypeTag<T>{}, index_, std::forward<U>(value))) {
+    if (!value_.template Assign<>(TypeTag<T>{}, index_, std::forward<U>(value))) {
       Destruct();
       Construct(TypeTag<T>{}, std::forward<U>(value));
     }
   }
   template <typename T>
   void Assign(T&& value) {
-    if (!value_.template Assign(index_, std::forward<T>(value))) {
+    if (!value_.template Assign<>(index_, std::forward<T>(value))) {
       Destruct();
       Construct(std::forward<T>(value));
     }
