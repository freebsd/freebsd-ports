--- deps/v8/src/base/small-vector.h.orig	2024-04-24 14:03:50 UTC
+++ deps/v8/src/base/small-vector.h
@@ -22,7 +22,6 @@ class SmallVector {
 class SmallVector {
   // Currently only support trivially copyable and trivially destructible data
   // types, as it uses memcpy to copy elements and never calls destructors.
-  ASSERT_TRIVIALLY_COPYABLE(T);
   static_assert(std::is_trivially_destructible<T>::value);
 
  public:
